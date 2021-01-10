<?xml version="1.0" encoding="ISO-8859-1"?>
<StyledLayerDescriptor version="1.0.0" 
		xsi:schemaLocation="http://www.opengis.net/sld StyledLayerDescriptor.xsd" 
		xmlns="http://www.opengis.net/sld" 
		xmlns:ogc="http://www.opengis.net/ogc" 
		xmlns:xlink="http://www.w3.org/1999/xlink" 
		xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
  <!-- a named layer is the basic building block of an sld document -->

  <NamedLayer>
    <Name>Default Point</Name>
    <UserStyle>
      <!-- they have names, titles and abstracts -->

      <Title>A boring default style</Title>
      <Abstract>A sample style that just prints out a purple square</Abstract>
      <!-- FeatureTypeStyles describe how to render different features -->
      <!-- a feature type for points -->

      <FeatureTypeStyle>
        <!--FeatureTypeName>Feature</FeatureTypeName-->
        <Rule>
          <Name>Rule 1</Name>
          <Title>RedSquare</Title>
          <Abstract>A red fill with an 6 pixel size</Abstract>

          <!-- like a linesymbolizer but with a fill too -->
          <PointSymbolizer>
            <Graphic>
              <Mark>
                <WellKnownName>square</WellKnownName>
                <Fill>
                  <CssParameter name="fill">#00FF00</CssParameter>
                </Fill>
              </Mark>
              <Size>12</Size>
            </Graphic>
          </PointSymbolizer>
        </Rule>

      </FeatureTypeStyle>

      <FeatureTypeStyle>
        <Name>text1</Name>
        <Rule>

          <TextSymbolizer>

            <Label>
              <ogc:Function name="strSubstring">
                <ogc:PropertyName>TEXTSTRING</ogc:PropertyName>
                <ogc:Add >
                  <ogc:Function name="strIndexOf">
                    <ogc:PropertyName>TEXTSTRING</ogc:PropertyName>
                    <ogc:Literal>\L</ogc:Literal>
                  </ogc:Function>
                  <ogc:Literal>2</ogc:Literal>
                </ogc:Add >
                <ogc:Function name="strIndexOf">
                  <ogc:PropertyName>TEXTSTRING</ogc:PropertyName>
                  <ogc:Literal>}</ogc:Literal>
                </ogc:Function>
              </ogc:Function>
            </Label>

            <Font>
              <CssParameter name="font-family">
                <ogc:Function name="strSubstring">
                  <ogc:PropertyName>TEXTSTRING</ogc:PropertyName>
                  <ogc:Add >
                    <ogc:Function name="strIndexOf">
                      <ogc:PropertyName>TEXTSTRING</ogc:PropertyName>
                      <ogc:Literal>\f</ogc:Literal>
                    </ogc:Function>
                    <ogc:Literal>2</ogc:Literal>
                  </ogc:Add >
                  <ogc:Function name="strIndexOf">
                    <ogc:PropertyName>TEXTSTRING</ogc:PropertyName>
                    <ogc:Literal>|b</ogc:Literal>
                  </ogc:Function>
                </ogc:Function>
              </CssParameter>
              
              <CssParameter name="font-size">
                 <ogc:Function name="strSubstring">
                  <ogc:PropertyName>TEXTSTRING</ogc:PropertyName>
                  <ogc:Add >
                    <ogc:Function name="strIndexOf">
                      <ogc:PropertyName>TEXTSTRING</ogc:PropertyName>
                      <ogc:Literal>|p</ogc:Literal>
                    </ogc:Function>
                    <ogc:Literal>2</ogc:Literal>
                  </ogc:Add >
                  <ogc:Function name="strIndexOf">
                    <ogc:PropertyName>TEXTSTRING</ogc:PropertyName>
                    <ogc:Literal>;\L</ogc:Literal>
                  </ogc:Function>
                </ogc:Function>
              
              </CssParameter>

              <CssParameter name="font-weight">normal</CssParameter>
            </Font>
            <LabelPlacement>
              <PointPlacement>
                <AnchorPoint>
                  <AnchorPointX>0</AnchorPointX>
                  <AnchorPointY>0.0</AnchorPointY>
                </AnchorPoint>
              </PointPlacement>
            </LabelPlacement>
            <Halo>
              <Radius>0.1</Radius>
              <Fill>
                <CssParameter name="fill">#DDDDDD</CssParameter>
              </Fill>
            </Halo>
            <Fill>
              <CssParameter name="fill">
                #0000FF
              </CssParameter>
            </Fill>
          </TextSymbolizer>
        </Rule>
      </FeatureTypeStyle>

    </UserStyle>
  </NamedLayer>
</StyledLayerDescriptor>

