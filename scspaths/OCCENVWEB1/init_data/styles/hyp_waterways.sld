<?xml version="1.0" encoding="ISO-8859-1"?>
<StyledLayerDescriptor version="1.0.0"
    xsi:schemaLocation="http://www.opengis.net/sld StyledLayerDescriptor.xsd"
    xmlns="http://www.opengis.net/sld"
    xmlns:ogc="http://www.opengis.net/ogc"
    xmlns:xlink="http://www.w3.org/1999/xlink"
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
<NamedLayer>
<Name> </Name>
  <UserStyle>
    <Title>waterway layer</Title>
    <FeatureTypeStyle> <Rule>
      <MinScaleDenominator>272000</MinScaleDenominator>
      <Name>waterway river edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>river</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">2</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MinScaleDenominator>272000</MinScaleDenominator>
      <Name>waterway river fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>river</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">1</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">10</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#445968</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>0</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#445968</CssParameter> </Fill>
        <VendorOption name="maxDisplacement">50</VendorOption>
        <VendorOption name="repeat">300</VendorOption>
        <VendorOption name="labelAllGroup">true</VendorOption>
        <VendorOption name="removeOverlaps">true</VendorOption>
        <VendorOption name="followLine">true</VendorOption>
        <VendorOption name="group">true</VendorOption>
      </TextSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>272000</MaxScaleDenominator>
      <MinScaleDenominator>68000</MinScaleDenominator>
      <Name>waterway river edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>river</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">4</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>272000</MaxScaleDenominator>
      <MinScaleDenominator>68000</MinScaleDenominator>
      <Name>waterway river fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>river</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">2</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">10</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#445968</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>0</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#445968</CssParameter> </Fill>
        <VendorOption name="maxDisplacement">50</VendorOption>
        <VendorOption name="repeat">300</VendorOption>
        <VendorOption name="labelAllGroup">true</VendorOption>
        <VendorOption name="removeOverlaps">true</VendorOption>
        <VendorOption name="followLine">true</VendorOption>
        <VendorOption name="group">true</VendorOption>
      </TextSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>68000</MaxScaleDenominator>
      <MinScaleDenominator>11300</MinScaleDenominator>
      <Name>waterway river edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>river</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">8</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>68000</MaxScaleDenominator>
      <MinScaleDenominator>11300</MinScaleDenominator>
      <Name>waterway river fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>river</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">6</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">10</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#445968</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>0</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#445968</CssParameter> </Fill>
        <VendorOption name="maxDisplacement">50</VendorOption>
        <VendorOption name="repeat">300</VendorOption>
        <VendorOption name="labelAllGroup">true</VendorOption>
        <VendorOption name="removeOverlaps">true</VendorOption>
        <VendorOption name="followLine">true</VendorOption>
        <VendorOption name="group">true</VendorOption>
      </TextSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>11300</MaxScaleDenominator>
      <Name>waterway river edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>river</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">14</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>11300</MaxScaleDenominator>
      <Name>waterway river fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>river</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">12</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">12</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#445968</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>0</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#445968</CssParameter> </Fill>
        <VendorOption name="maxDisplacement">50</VendorOption>
        <VendorOption name="repeat">300</VendorOption>
        <VendorOption name="labelAllGroup">true</VendorOption>
        <VendorOption name="removeOverlaps">true</VendorOption>
        <VendorOption name="followLine">true</VendorOption>
        <VendorOption name="group">true</VendorOption>
      </TextSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MinScaleDenominator>68000</MinScaleDenominator>
      <Name>waterway stream edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>stream</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">1</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MinScaleDenominator>68000</MinScaleDenominator>
      <Name>waterway stream fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>stream</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">1</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">8</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#344958</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>0</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#344958</CssParameter> </Fill>
        <VendorOption name="maxDisplacement">50</VendorOption>
        <VendorOption name="repeat">300</VendorOption>
        <VendorOption name="labelAllGroup">true</VendorOption>
        <VendorOption name="removeOverlaps">true</VendorOption>
        <VendorOption name="followLine">true</VendorOption>
        <VendorOption name="group">true</VendorOption>
      </TextSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>68000</MaxScaleDenominator>
      <MinScaleDenominator>11300</MinScaleDenominator>
      <Name>waterway stream edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>stream</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">4</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>68000</MaxScaleDenominator>
      <MinScaleDenominator>11300</MinScaleDenominator>
      <Name>waterway stream fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>stream</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">2</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">8</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#344958</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>0</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#344958</CssParameter> </Fill>
        <VendorOption name="maxDisplacement">50</VendorOption>
        <VendorOption name="repeat">300</VendorOption>
        <VendorOption name="labelAllGroup">true</VendorOption>
        <VendorOption name="removeOverlaps">true</VendorOption>
        <VendorOption name="followLine">true</VendorOption>
        <VendorOption name="group">true</VendorOption>
      </TextSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>11300</MaxScaleDenominator>
      <Name>waterway stream edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>stream</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">8</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>11300</MaxScaleDenominator>
      <Name>waterway stream fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>stream</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">6</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">10</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#344958</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>0</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#344958</CssParameter> </Fill>
        <VendorOption name="maxDisplacement">50</VendorOption>
        <VendorOption name="repeat">300</VendorOption>
        <VendorOption name="labelAllGroup">true</VendorOption>
        <VendorOption name="removeOverlaps">true</VendorOption>
        <VendorOption name="followLine">true</VendorOption>
        <VendorOption name="group">true</VendorOption>
      </TextSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MinScaleDenominator>68000</MinScaleDenominator>
      <Name>waterway canal edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>canal</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">1</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MinScaleDenominator>68000</MinScaleDenominator>
      <Name>waterway canal fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>canal</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">1</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">8</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#344958</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>0</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#344958</CssParameter> </Fill>
        <VendorOption name="maxDisplacement">50</VendorOption>
        <VendorOption name="repeat">300</VendorOption>
        <VendorOption name="labelAllGroup">true</VendorOption>
        <VendorOption name="removeOverlaps">true</VendorOption>
        <VendorOption name="followLine">true</VendorOption>
        <VendorOption name="group">true</VendorOption>
      </TextSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>68000</MaxScaleDenominator>
      <MinScaleDenominator>11300</MinScaleDenominator>
      <Name>waterway canal edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>canal</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">4</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>68000</MaxScaleDenominator>
      <MinScaleDenominator>11300</MinScaleDenominator>
      <Name>waterway canal fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>canal</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">2</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">8</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#344958</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>0</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#344958</CssParameter> </Fill>
        <VendorOption name="maxDisplacement">50</VendorOption>
        <VendorOption name="repeat">300</VendorOption>
        <VendorOption name="labelAllGroup">true</VendorOption>
        <VendorOption name="removeOverlaps">true</VendorOption>
        <VendorOption name="followLine">true</VendorOption>
        <VendorOption name="group">true</VendorOption>
      </TextSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>11300</MaxScaleDenominator>
      <Name>waterway canal edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>canal</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">8</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>11300</MaxScaleDenominator>
      <Name>waterway canal fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>canal</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6479C2</CssParameter>
        <CssParameter name="stroke-width">6</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">10</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#344958</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>0</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#344958</CssParameter> </Fill>
        <VendorOption name="maxDisplacement">50</VendorOption>
        <VendorOption name="repeat">300</VendorOption>
        <VendorOption name="labelAllGroup">true</VendorOption>
        <VendorOption name="removeOverlaps">true</VendorOption>
        <VendorOption name="followLine">true</VendorOption>
        <VendorOption name="group">true</VendorOption>
      </TextSymbolizer>
    </Rule> </FeatureTypeStyle>
  </UserStyle>
</NamedLayer>

</StyledLayerDescriptor>