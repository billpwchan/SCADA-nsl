
import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { StompRService} from '@stomp/ng2-stompjs';
import { AgGridModule } from "ag-grid-angular/main";
import { AppComponent } from './app.component';
import { HttpClientModule } from "@angular/common/http";
import { FormsModule } from '@angular/forms';
import { MaterialModule } from './material.module';
import { CookieService } from 'ngx-cookie-service';
import Stomp from 'stompjs';

@NgModule({
  declarations: [
    AppComponent
  ],
  imports: [
    HttpClientModule ,
    BrowserModule,
    FormsModule,
    MaterialModule,
    AgGridModule.withComponents([ ])
  ],
  providers: [
      StompRService,
      CookieService
    ],
  bootstrap: [AppComponent]
})
export class AppModule { }
