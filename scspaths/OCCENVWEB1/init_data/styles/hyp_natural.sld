<?xml version="1.0" encoding="ISO-8859-1"?>
<StyledLayerDescriptor version="1.0.0"
xsi:schemaLocation="http://www.opengis.net/sld StyledLayerDescriptor.xsd"
xmlns="http://www.opengis.net/sld"
xmlns:ogc="http://www.opengis.net/ogc"
xmlns:xlink="http://www.w3.org/1999/xlink"
xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
  <NamedLayer>
    <Name>natural layer</Name>
    <UserStyle>
      <Title></Title>
      <FeatureTypeStyle>
        <Rule>
          <Name>riverbank</Name>
          <ogc:Filter> <ogc:PropertyIsEqualTo>
            <ogc:PropertyName>type</ogc:PropertyName>
            <ogc:Literal>riverbank</ogc:Literal>
            </ogc:PropertyIsEqualTo> </ogc:Filter>
          <PolygonSymbolizer>
            <Fill>
              <CssParameter name="fill">#6479C2</CssParameter>
            </Fill>
            <Stroke>
              <CssParameter name="stroke">#6479C2</CssParameter>
              <CssParameter name="stroke-width">1</CssParameter>
            </Stroke>
          </PolygonSymbolizer>        
        </Rule>
        
        <Rule>
          <Name>water</Name>
          <ogc:Filter> <ogc:PropertyIsEqualTo>
            <ogc:PropertyName>type</ogc:PropertyName>
            <ogc:Literal>water</ogc:Literal>
            </ogc:PropertyIsEqualTo> </ogc:Filter>
          <PolygonSymbolizer>
            <Fill>
              <CssParameter name="fill">#6479C2</CssParameter>
            </Fill>
            <Stroke>
              <CssParameter name="stroke">#6479C2</CssParameter>
              <CssParameter name="stroke-width">1</CssParameter>
            </Stroke>
          </PolygonSymbolizer>        
        </Rule>
        
        <Rule>
          <Name>forest</Name>
          <ogc:Filter> <ogc:PropertyIsEqualTo>
            <ogc:PropertyName>type</ogc:PropertyName>
            <ogc:Literal>forest</ogc:Literal>
            </ogc:PropertyIsEqualTo> </ogc:Filter>
          <PolygonSymbolizer>
            <Fill>
              <CssParameter name="fill">#637663</CssParameter>
            </Fill>
            <Stroke>
              <CssParameter name="stroke">#637663</CssParameter>
              <CssParameter name="stroke-width">1</CssParameter>
            </Stroke>
          </PolygonSymbolizer>
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
                  <AnchorPointY>0.5</AnchorPointY>
                </AnchorPoint>
              </PointPlacement>
            </LabelPlacement>
            <Halo>
              <Radius>1</Radius>
              <Fill>
                <CssParameter name="fill">#DDDDDD</CssParameter>
              </Fill>
            </Halo>
            <Fill>
              <CssParameter name="fill">#314331</CssParameter>
            </Fill>
            <VendorOption name="autoWrap">60</VendorOption>
            <VendorOption name="maxDisplacement">150</VendorOption>
          </TextSymbolizer>
          
        </Rule>
        
        <Rule>
          <Name>park</Name>
          <ogc:Filter> <ogc:PropertyIsEqualTo>
            <ogc:PropertyName>type</ogc:PropertyName>
            <ogc:Literal>park</ogc:Literal>
            </ogc:PropertyIsEqualTo> </ogc:Filter>
          <PolygonSymbolizer>
            <Fill>
              <CssParameter name="fill">#738673</CssParameter>
            </Fill>
            <Stroke>
              <CssParameter name="stroke">#738673</CssParameter>
              <CssParameter name="stroke-width">1</CssParameter>
            </Stroke>
          </PolygonSymbolizer>
        </Rule>
        
      </FeatureTypeStyle>
    </UserStyle>
  </NamedLayer>
</StyledLayerDescriptor>