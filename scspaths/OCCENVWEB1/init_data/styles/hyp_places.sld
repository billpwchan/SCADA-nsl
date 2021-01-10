<?xml version="1.0" encoding="ISO-8859-1"?>
<StyledLayerDescriptor version="1.0.0" 
xsi:schemaLocation="http://www.opengis.net/sld StyledLayerDescriptor.xsd" 
xmlns="http://www.opengis.net/sld" 
xmlns:ogc="http://www.opengis.net/ogc" 
xmlns:xlink="http://www.w3.org/1999/xlink" 
xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
  <NamedLayer>
    <Name>places layer</Name>
    <UserStyle>
      <Title></Title>
      <FeatureTypeStyle>
        <Rule>
          <Name>city</Name>
          <ogc:Filter> <ogc:PropertyIsEqualTo>
            <ogc:PropertyName>type</ogc:PropertyName>
            <ogc:Literal>city</ogc:Literal>
            </ogc:PropertyIsEqualTo>
          </ogc:Filter>
          <!--          
          <PointSymbolizer>
          <Graphic>
          <Mark>
          <WellKnownName>circle</WellKnownName>
          <Fill>
          <CssParameter name="fill">#0000FF</CssParameter>
        </Fill>
        </Mark>
          <Size>2</Size>
        </Graphic>
        </PointSymbolizer>
          -->
          <TextSymbolizer>
            <Label>
              <ogc:PropertyName>name</ogc:PropertyName>
            </Label>
            <Font>
              <CssParameter name="font-family">Arial</CssParameter>
              <CssParameter name="font-size">14</CssParameter>
              <CssParameter name="font-style">normal</CssParameter>
              <CssParameter name="font-weight">bold</CssParameter>
            </Font>
            <LabelPlacement>
              <PointPlacement>
                <AnchorPoint>
                  <AnchorPointX>0.5</AnchorPointX>
                  <AnchorPointY>0.0</AnchorPointY>
                </AnchorPoint>
              </PointPlacement>
            </LabelPlacement>
            <Halo>
              <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
              <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
            </Halo>
            <Fill>
              <CssParameter name="fill">#000000</CssParameter>
            </Fill>
          </TextSymbolizer>
        </Rule>
      </FeatureTypeStyle>
      
      <FeatureTypeStyle>      
        <Rule>
          <Name>suburb and town</Name>
          <MaxScaleDenominator>272000</MaxScaleDenominator>
          <ogc:Filter>
            <ogc:Or>
              <ogc:PropertyIsEqualTo>
                <ogc:PropertyName>type</ogc:PropertyName>
                <ogc:Literal>suburb</ogc:Literal>
              </ogc:PropertyIsEqualTo>
              <ogc:PropertyIsEqualTo>
                <ogc:PropertyName>type</ogc:PropertyName>
                <ogc:Literal>town</ogc:Literal>
              </ogc:PropertyIsEqualTo>
            </ogc:Or>
          </ogc:Filter>
          <TextSymbolizer>
            <Label>
              <ogc:PropertyName>name</ogc:PropertyName>
            </Label>
            <Font>
              <CssParameter name="font-family">Arial</CssParameter>
              <CssParameter name="font-size">12</CssParameter>
              <CssParameter name="font-style">normal</CssParameter>
            </Font>
            <LabelPlacement>
              <PointPlacement>
                <AnchorPoint>
                  <AnchorPointX>0.5</AnchorPointX>
                  <AnchorPointY>0.0</AnchorPointY>
                </AnchorPoint>
              </PointPlacement>
            </LabelPlacement>
            <Halo>
              <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
              <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
            </Halo>
            <Fill>
              <CssParameter name="fill">#333333</CssParameter>
            </Fill>
          </TextSymbolizer>
        </Rule>
      </FeatureTypeStyle>

      <FeatureTypeStyle>      
        <Rule>
          <Name>locality</Name>
          <MaxScaleDenominator>72000</MaxScaleDenominator>
          <ogc:Filter>
              <ogc:PropertyIsEqualTo>
                <ogc:PropertyName>type</ogc:PropertyName>
                <ogc:Literal>locality</ogc:Literal>
              </ogc:PropertyIsEqualTo>
          </ogc:Filter>
          <TextSymbolizer>
            <Label>
              <ogc:PropertyName>name</ogc:PropertyName>
            </Label>
            <Font>
              <CssParameter name="font-family">Arial</CssParameter>
              <CssParameter name="font-size">10</CssParameter>
              <CssParameter name="font-style">normal</CssParameter>
            </Font>
            <LabelPlacement>
              <PointPlacement>
                <AnchorPoint>
                  <AnchorPointX>0.5</AnchorPointX>
                  <AnchorPointY>0.0</AnchorPointY>
                </AnchorPoint>
              </PointPlacement>
            </LabelPlacement>
            <Halo>
              <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
              <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
            </Halo>
            <Fill>
              <CssParameter name="fill">#555555</CssParameter>
            </Fill>
          </TextSymbolizer>
        </Rule>
      </FeatureTypeStyle>      
      
    </UserStyle>
  </NamedLayer>
</StyledLayerDescriptor>