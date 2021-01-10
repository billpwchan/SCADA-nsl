import { Component } from "@angular/core";
import { StompRService, StompState } from "@stomp/ng2-stompjs";
import { Message, Frame } from "@stomp/stompjs";
import { Observable } from "rxjs/Observable";
import "rxjs/add/operator/map";
import { HttpClient } from "@angular/common/http";
import { GridOptions, GridApi, RowNode } from "ag-grid";
import { Subscription } from "rxjs/Subscription";
import { ScsRESTRequest, ScsResponse } from "./scsrequest";
import { CookieService } from 'ngx-cookie-service';
//import * as Stomp from '@stomp/stompjs';

@Component({
  selector: "app-root",
  template: `
    <!--The content below is only a placeholder and can be replaced.-->
    <div style="text-align:center">
      <h2>
        OLS Viewer: nb entries {{entries}} Stomp: {{stompStatus}}
      </h2>
    </div>
	
    <div>
      Server: <input (keyup)="onServerKey($event)" value='AlmServer'>
      ListName: <input (keyup)="onListKey($event)" value='AlarmList'>
      <button (click)="onSubscribeTopic()" [disabled]="sub != null">Subscribe</button>
    <button (click)="onUnSubscribeTopic()" [disabled]="sub == null">UnSubscribe</button>
    <button (click)="onExport()" [disabled]="sub == null">Export</button>
    <button (click)="onFreeze()" [disabled]="isFrozen==true">Freeze</button>
    <button (click)="onUnfreeze()" [disabled]="isFrozen==false">Unfreeze</button>
    </div>
    
    <div>
		<ag-grid-angular style="width: 95%; height: 200px;" class="ag-theme-fresh"
           (rowDoubleClicked)="onRowClicked($event)"
           (selectionChanged)="onSelectionChanged($event)"
           (rowSelected)="onRowSelected($event)"
					 [rowData]="rowData"
					 [gridOptions]="_gridOptions"
           [columnDefs]="columnDefs"
           [getRowNodeId]="getRowNodeId"
					 enableColResize="true"
           enableSorting="true"
           animateRows="false"
           enableCellChangeFlash="true"
           enableFilter="true"
           rowDeselection="true"
					 rowSelection="single">
		</ag-grid-angular>
    </div>
    <div>
        {{message}}
    </div>
  `,
  styles: []
})
export class AppComponent {
  _gridOptions: GridOptions;
  rowData: any;
  columnDefs: any;
  entries = 0;
  message: string;
  serverName: string;
  listName: string;
  currentSequence: number;
  sub: Subscription;
  isFrozen: boolean;
  stompStatus: string;
  getRowNodeId;
  pendingUpdate: any[];
  response_subscription: Subscription;
  selectedNodeID: string;
  //private stompClient;

  cookieTokenValue = 'UNKNOWN';
  cookieTokenExists: boolean = false;

  constructor(private http: HttpClient, private cookieService: CookieService, private stompService: StompRService) {
    
    this.columnDefs = [
      {
        headerName: "Time",
        field: "AcquisitionDate",
        valueFormatter: AppComponent.timeFormat, maxWidth: 200, sort: "desc"
      },
      { headerName: "AlarmId", field: "AlarmId", maxWidth: 100 },
      {
        headerName: "AckReq",
        field: "AcknowledgeRequired",
        valueFormatter: AppComponent.ackFormat, maxWidth: 100
      },
      { headerName: "Severity", field: "Severity", maxWidth: 100 },
      { headerName: "Message", field: "Message", tooltipField: "Message" }
    ];

    this.listName = "AlarmList";
    this.serverName = "AlmServer";
    this.isFrozen = false;
    
    this.getRowNodeId = function(data) {
      return data.ID;
    };

    this._gridOptions = <GridOptions>{
      onGridSizeChanged: () => this._gridOptions.api.sizeColumnsToFit(),
      getRowStyle: AppComponent.getRowStyleScheduled
    };

    this.currentSequence = -2;
    this.rowData = [];
    this.sub = null;
    this.pendingUpdate = [];

    this.initStomp();
    this.stompService.state
      .map((state: number) => StompState[state])
      .subscribe((status: string) => {
        this.stompStatus = status;
        if (status === "CONNECTED") {
          this.onSubscribeTopic();
        } else {
          this.onUnSubscribeTopic();
        }
      });
    this.message = "";
  }

  public onFreeze() {
    this.isFrozen =true;
  }

  public onUnfreeze() {
    this.isFrozen = false;
   
    // check if we have pending update
    for (let i = 0; i < this.pendingUpdate.length; i++) {
      if (this.pendingUpdate[i].sequence == this.currentSequence + 1) {
        this.currentSequence = this.pendingUpdate[i].sequence;
        
        let response = this.pendingUpdate[i];
        // update grid
        let transaction: any = {};
        if (response.deleted != undefined) {
          transaction.remove = response.deleted;
          this.entries -= response.deleted.length;
        }
        if (response.updated != undefined) {
          transaction.update = response.updated;
        }
        if (response.created != undefined) {
          transaction.add = response.created;
          this.entries += response.created.length;
        }
        this._gridOptions.api.updateRowData(transaction);
      }
    }
    if (this.selectedNodeID != null) {
      console.log("ensureNodeVisible: " + this.selectedNodeID);
      this._gridOptions.api.ensureNodeVisible((node: RowNode) => this.selectedNodeID === node.data.ID, "top");
    } else {
      console.log("ensureIndexVisible: 0");
      this._gridOptions.api.ensureIndexVisible(0, "top");
    }
    this.pendingUpdate = [];
  }

  private initStomp() {
    let cookieName = (<any>window).token_cookie_name;
    this.cookieTokenExists = this.cookieService.check(cookieName);
    if (this.cookieTokenExists) {
      this.cookieTokenValue = this.cookieService.get(cookieName);
    }
    /*let url = "ws://" + (<any>window).backend_endpoint + "/scswsgw";   
    let ws = new WebSocket(url, ['v10.stomp', 'v11.stomp', 'v12.stomp']);
    
    this.stompClient = Stomp.over(ws);

    var headers = {
      // additional header
      'tokenKey': this.cookieTokenValue
    };

    var connect_callback = function(frame) {
      // called back after the client is connected and authenticated to the STOMP server
      alert("connect_callback: WS connection OK " + frame);
    };

    var error_callback = function(error) {
      // display the error's message header:
      alert(error);
    };

    this.stompClient.connect(headers, connect_callback, error_callback);
    */
    this.stompService.config = {
      // Which server?
      url: "ws://" + (<any>window).backend_endpoint + "/scswsgw",
      // Headers
      // Typical keys: login, passcode, host
      headers: {
        // login: 'guest',  passcode: 'guest'
        'tokenKey': this.cookieTokenValue
      },
      // How often to heartbeat?
      // Interval in milliseconds, set to 0 to disable
      heartbeat_in: 20000, // Typical value 0 - disabled
      heartbeat_out: 20000, // Typical value 20000 - every 20 seconds

      reconnect_delay: 5000, // Wait in milliseconds before attempting auto reconnect
      debug: false // Will log diagnostics on console
    };
    
    this.stompService.initAndConnect();
  }

  onExport() {
    this._gridOptions.api.exportDataAsCsv();
  }

  onServerKey(event) {
    this.serverName = event.target.value;
  }

  onListKey(event) {
    this.listName = event.target.value;
  }

  onUnSubscribeTopic() {
    this.rowData = [];
    this.pendingUpdate = [];
    this.entries = 0;
    this.message = "";
    this.currentSequence = -2;
    if (this.sub != null) {
      this.sub.unsubscribe();
      this.sub = null;
    }
    if (this.response_subscription != null) {
      this.response_subscription.unsubscribe();
      this.response_subscription = null;
    }
  }

  onSubscribeTopic() {
    this.currentSequence = -1;
  
    let stomp_response_subscription = this.stompService.subscribe("/user/queue/scsresponse");

    this.response_subscription = stomp_response_subscription.subscribe((stompframe: Frame) => {
      let o = JSON.parse(stompframe.body) as ScsResponse;
      //console.log(JSON.stringify(stompframe.headers));
      console.log(o.component + " " + o.request);
      this.message = "";

      if (o.component === "OlsTopicComponent") {
        this.currentSequence = o.response.sequence;
        if (o.response.currentData != undefined) {
          this.rowData = o.response.currentData;
          this.entries = this.rowData.length;
        } else {
          this.entries = 0;
        }
      }
    });

    let stomp_subscription = this.stompService.subscribe("/topic/" + this.serverName + '.' + this.listName);

    this.sub = stomp_subscription.subscribe((stompframe: Frame) => {
      // decode message
      let o = JSON.parse(stompframe.body);
      let seq = o.response.sequence;
      console.log(
        "STOMP seq: " + seq + " current seq: " + this.currentSequence
      );

      if (this.isFrozen) {
        // connection has been requested
        this.pendingUpdate.push(o.response);
        return;
      }

      if (this.currentSequence + 1 == seq) {
        this.currentSequence = seq;
        this.updateGrid(o.response);
        return;
      }

      if (this.currentSequence < 0) {
        // connection has been requested
        this.pendingUpdate.push(o.response);
        return;
      }
      
      if (this.currentSequence + 1 != seq) {
        // check if we have pending update
        for (let i = 0; i < this.pendingUpdate.length; i++) {
          if (this.pendingUpdate[i].sequence == this.currentSequence + 1) {
            this.currentSequence = this.pendingUpdate[i].sequence;
            this.updateGrid(this.pendingUpdate[i]);
          }
        }
        this.pendingUpdate = [];

        if (this.currentSequence + 1 != seq) {
          console.error("sequence error need to restart");
          this.currentSequence = -2;
          let req = new ScsRESTRequest("OlsTopicComponent", "GetCurrentOlsTopicData", "Olstest");
          req.parameters = {};
          req.parameters.listName = this.listName;
          req.parameters.listServer = this.serverName;

          //this.stompClient.publish('/app/scsrequest', JSON.stringify(req));
          this.stompService.publish('/app/scsrequest', JSON.stringify(req));
          return;
        }
      }

      this.currentSequence = seq;
      this.updateGrid(o.response);
    });

    let req = new ScsRESTRequest("OlsTopicComponent", "GetCurrentOlsTopicData", "Olstest");
    req.parameters = {};
    req.parameters.listName = this.listName;
    req.parameters.listServer = this.serverName;

    //this.stompClient.publish('/app/scsrequest', JSON.stringify(req));
    this.stompService.publish('/app/scsrequest', JSON.stringify(req));
    
  }

  private updateGrid(response: any) {
    // update grid
    let transaction: any = {};
    if (response.deleted != undefined) {
      transaction.remove = response.deleted;
      this.entries -= response.deleted.length;
    }
    if (response.updated != undefined) {
      transaction.update = response.updated;
    }
    if (response.created != undefined) {
      transaction.add = response.created;
      this.entries += response.created.length;
    }
    this._gridOptions.api.updateRowData(transaction);

    if (this.selectedNodeID != null) {
      console.log("ensureNodeVisible: " + this.selectedNodeID);
      this._gridOptions.api.ensureNodeVisible((node: RowNode) => this.selectedNodeID === node.data.ID, "top");
    } else {
      console.log("ensureIndexVisible: 0");
      this._gridOptions.api.ensureIndexVisible(0, "top");
    }
  }

  private static getRowStyleScheduled(params: any) {
    let fstyle = "normal";
    let fweight = "normal";
    let textcolor:string = "#111111";
    let opacity = "1";
    let bgcolor = "#43a047"; // green 600

    if (params.data.AcknowledgeRequired === 1) {
      fweight = "bold";
    }

    if (params.data.Severity === 2) {
      bgcolor = "#fdd835"; // yellow 600
    } else if (params.data.Severity === 3) {
      bgcolor = "#fb8c00"; // orange 600
    } else if (params.data.Severity === 4) {
      bgcolor = "#e53935"; // red 600
    }

    if (params.node.selected) {
      fstyle = "italic";
      textcolor = "blue";
      bgcolor = "#00701a"; // green dark
      if (params.data.Severity === 2) {
        bgcolor = "#c6a700"; // yellow dark
      } else if (params.data.Severity === 3) {
        bgcolor = "#c25e00"; // orange dark
      } else if (params.data.Severity === 4) {
        bgcolor = "#ab000d"; // red dark
      }
    }

    return {
      "background-color": bgcolor,
      "color": textcolor,
      "opacity": opacity,
      "font-weight": fweight,
      "font-style": fstyle
    };
  }

  onRowSelected(event): void {
    if (event.node.selected) {
      
    }
    
  }

  onSelectionChanged(event): void {
    this.selectedNodeID = null;
    let gapi = event.api as GridApi;
    if (gapi.getSelectedNodes().length == 1) {
      this.selectedNodeID = gapi.getSelectedNodes()[0].data.ID;
      console.log("Selected node: " + this.selectedNodeID);
    } else {
      console.log("No selection");
    }
    gapi.redrawRows();
  }

  onRowClicked(event): void {
    let req = new ScsRESTRequest("AlmComponent", "AckAlarm", "Olstest");
    req.parameters = {};
    req.parameters.comment = "double click";
    req.parameters.alarmId = event.data.ID;

    //this.stompClient.publish('/app/scsrequest', JSON.stringify(req));
    this.stompService.publish('/app/scsrequest', JSON.stringify(req));
    
  }

  private static timeFormat(inTime: any): string {
    let sp = inTime.value.split(" ");
    let t = new Date(1970, 0, 1); // Epoch
    t.setUTCSeconds(sp[0]);
    return t.toLocaleString();
  }

  private static ackFormat(inVal: any): string {
    if (inVal.value == 0) {
      return "No";
    }
    return "Yes";
  }
}
