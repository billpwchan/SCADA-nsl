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
    <Title>road layer</Title>
  
    <FeatureTypeStyle> <Rule>
      <MinScaleDenominator>272000</MinScaleDenominator>
      <Name>road primary edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>primary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#666166</CssParameter>
        <CssParameter name="stroke-width">2</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MinScaleDenominator>272000</MinScaleDenominator>
      <Name>road primary fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>primary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#514D51</CssParameter>
        <CssParameter name="stroke-width">1</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">14</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#162116</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>10</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#162116</CssParameter> </Fill>
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
      <Name>road primary edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>primary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#666166</CssParameter>
        <CssParameter name="stroke-width">5</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>272000</MaxScaleDenominator>
      <MinScaleDenominator>68000</MinScaleDenominator>
      <Name>road primary fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>primary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#514D51</CssParameter>
        <CssParameter name="stroke-width">3</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">14</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#162116</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>10</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#162116</CssParameter> </Fill>
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
      <Name>road primary edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>primary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#666166</CssParameter>
        <CssParameter name="stroke-width">8</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>68000</MaxScaleDenominator>
      <MinScaleDenominator>11300</MinScaleDenominator>
      <Name>road primary fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>primary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#514D51</CssParameter>
        <CssParameter name="stroke-width">6</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">14</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#162116</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>10</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#162116</CssParameter> </Fill>
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
      <Name>road primary edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>primary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#666166</CssParameter>
        <CssParameter name="stroke-width">12</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>11300</MaxScaleDenominator>
      <Name>road primary fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>primary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#514D51</CssParameter>
        <CssParameter name="stroke-width">8</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">14</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#162116</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>10</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#162116</CssParameter> </Fill>
        <VendorOption name="maxDisplacement">50</VendorOption>
        <VendorOption name="repeat">300</VendorOption>
        <VendorOption name="labelAllGroup">true</VendorOption>
        <VendorOption name="removeOverlaps">true</VendorOption>
        <VendorOption name="followLine">true</VendorOption>
        <VendorOption name="group">true</VendorOption>
      </TextSymbolizer>
    </Rule> </FeatureTypeStyle>
  
    <FeatureTypeStyle> <Rule>
      <MinScaleDenominator>272000</MinScaleDenominator>
      <Name>road secondary edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>secondary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#5D595D</CssParameter>
        <CssParameter name="stroke-width">1</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MinScaleDenominator>272000</MinScaleDenominator>
      <Name>road secondary fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>secondary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#494549</CssParameter>
        <CssParameter name="stroke-width">1</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">12</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#2D292D</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>10</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#2D292D</CssParameter> </Fill>
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
      <Name>road secondary edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>secondary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#5D595D</CssParameter>
        <CssParameter name="stroke-width">4</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>272000</MaxScaleDenominator>
      <MinScaleDenominator>68000</MinScaleDenominator>
      <Name>road secondary fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>secondary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#494549</CssParameter>
        <CssParameter name="stroke-width">2</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">12</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#2D292D</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>10</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#2D292D</CssParameter> </Fill>
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
      <Name>road secondary edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>secondary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#5D595D</CssParameter>
        <CssParameter name="stroke-width">5</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>68000</MaxScaleDenominator>
      <MinScaleDenominator>11300</MinScaleDenominator>
      <Name>road secondary fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>secondary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#494549</CssParameter>
        <CssParameter name="stroke-width">3</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">12</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#2D292D</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>10</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#2D292D</CssParameter> </Fill>
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
      <Name>road secondary edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>secondary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#5D595D</CssParameter>
        <CssParameter name="stroke-width">8</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>11300</MaxScaleDenominator>
      <Name>road secondary fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>secondary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#494549</CssParameter>
        <CssParameter name="stroke-width">6</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">12</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#2D292D</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>10</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#2D292D</CssParameter> </Fill>
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
      <Name>road tertiary edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>tertiary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#3A353A</CssParameter>
        <CssParameter name="stroke-width">2</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>68000</MaxScaleDenominator>
      <MinScaleDenominator>11300</MinScaleDenominator>
      <Name>road tertiary fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>tertiary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#373237</CssParameter>
        <CssParameter name="stroke-width">1</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">11</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#3A353A</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>10</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#3A353A</CssParameter> </Fill>
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
      <Name>road tertiary edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>tertiary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#3A353A</CssParameter>
        <CssParameter name="stroke-width">6</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>11300</MaxScaleDenominator>
      <Name>road tertiary fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>tertiary</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#373237</CssParameter>
        <CssParameter name="stroke-width">4</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">11</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#3A353A</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>10</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#3A353A</CssParameter> </Fill>
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
      <Name>road residential edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>residential</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#4A454A</CssParameter>
        <CssParameter name="stroke-width">2</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>68000</MaxScaleDenominator>
      <MinScaleDenominator>11300</MinScaleDenominator>
      <Name>road residential fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>residential</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#474247</CssParameter>
        <CssParameter name="stroke-width">1</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">10</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#3A353A</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>10</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#3A353A</CssParameter> </Fill>
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
      <Name>road residential edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>residential</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#4A454A</CssParameter>
        <CssParameter name="stroke-width">5</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>11300</MaxScaleDenominator>
      <Name>road residential fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>residential</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#474247</CssParameter>
        <CssParameter name="stroke-width">3</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">8</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#3A353A</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>10</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#3A353A</CssParameter> </Fill>
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
      <Name>road unclassified edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>unclassified</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#4A454A</CssParameter>
        <CssParameter name="stroke-width">1</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>68000</MaxScaleDenominator>
      <MinScaleDenominator>11300</MinScaleDenominator>
      <Name>road unclassified fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>unclassified</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#474247</CssParameter>
        <CssParameter name="stroke-width">1</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">9</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#3A353A</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>10</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#3A353A</CssParameter> </Fill>
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
      <Name>road unclassified edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>unclassified</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#4A454A</CssParameter>
        <CssParameter name="stroke-width">3</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>11300</MaxScaleDenominator>
      <Name>road unclassified fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>unclassified</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#474247</CssParameter>
        <CssParameter name="stroke-width">2</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">8</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#3A353A</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>10</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#3A353A</CssParameter> </Fill>
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
      <Name>road service edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>service</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#4A454A</CssParameter>
        <CssParameter name="stroke-width">1</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>68000</MaxScaleDenominator>
      <MinScaleDenominator>11300</MinScaleDenominator>
      <Name>road service fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>service</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#474247</CssParameter>
        <CssParameter name="stroke-width">1</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">9</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#3A353A</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>10</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#3A353A</CssParameter> </Fill>
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
      <Name>road service edge</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>service</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#4A454A</CssParameter>
        <CssParameter name="stroke-width">3</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>11300</MaxScaleDenominator>
      <Name>road service fill</Name>
      <ogc:Filter> <ogc:PropertyIsEqualTo>
        <ogc:PropertyName>type</ogc:PropertyName>
        <ogc:Literal>service</ogc:Literal>
      </ogc:PropertyIsEqualTo> </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#474247</CssParameter>
        <CssParameter name="stroke-width">2</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">8</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#3A353A</CssParameter>
        </Font>
        <LabelPlacement> <LinePlacement> <PerpendicularOffset>10</PerpendicularOffset> </LinePlacement> </LabelPlacement>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#3A353A</CssParameter> </Fill>
        <VendorOption name="maxDisplacement">50</VendorOption>
        <VendorOption name="repeat">300</VendorOption>
        <VendorOption name="labelAllGroup">true</VendorOption>
        <VendorOption name="removeOverlaps">true</VendorOption>
        <VendorOption name="followLine">true</VendorOption>
        <VendorOption name="group">true</VendorOption>
      </TextSymbolizer>
    </Rule> </FeatureTypeStyle>
  
    <FeatureTypeStyle> <Rule>
      <MinScaleDenominator>272000</MinScaleDenominator>
      <Name>road trunk edge</Name>
      <ogc:Filter>
      <ogc:PropertyIsLike  wildCard="*" singleChar="." escape="!">
      <ogc:PropertyName>type</ogc:PropertyName>
      <ogc:Literal>trunk*</ogc:Literal>
        </ogc:PropertyIsLike>
    </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#AA8388</CssParameter>
        <CssParameter name="stroke-width">4</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MinScaleDenominator>272000</MinScaleDenominator>
      <Name>roads trunk fill</Name>
      <ogc:Filter>
      <ogc:PropertyIsLike  wildCard="*" singleChar="." escape="!">
      <ogc:PropertyName>type</ogc:PropertyName>
      <ogc:Literal>trunk*</ogc:Literal>
        </ogc:PropertyIsLike>
    </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6d686d</CssParameter>
        <CssParameter name="stroke-width">2</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">16</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#162116</CssParameter>
        </Font>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#162116</CssParameter> </Fill>
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
      <Name>road trunk edge</Name>
      <ogc:Filter>
      <ogc:PropertyIsLike  wildCard="*" singleChar="." escape="!">
      <ogc:PropertyName>type</ogc:PropertyName>
      <ogc:Literal>trunk*</ogc:Literal>
        </ogc:PropertyIsLike>
    </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#AA8388</CssParameter>
        <CssParameter name="stroke-width">9</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>272000</MaxScaleDenominator>
      <MinScaleDenominator>68000</MinScaleDenominator>
      <Name>roads trunk fill</Name>
      <ogc:Filter>
      <ogc:PropertyIsLike  wildCard="*" singleChar="." escape="!">
      <ogc:PropertyName>type</ogc:PropertyName>
      <ogc:Literal>trunk*</ogc:Literal>
        </ogc:PropertyIsLike>
    </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6d686d</CssParameter>
        <CssParameter name="stroke-width">6</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">16</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#162116</CssParameter>
        </Font>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#162116</CssParameter> </Fill>
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
      <Name>road trunk edge</Name>
      <ogc:Filter>
      <ogc:PropertyIsLike  wildCard="*" singleChar="." escape="!">
      <ogc:PropertyName>type</ogc:PropertyName>
      <ogc:Literal>trunk*</ogc:Literal>
        </ogc:PropertyIsLike>
    </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#AA8388</CssParameter>
        <CssParameter name="stroke-width">12</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>68000</MaxScaleDenominator>
      <MinScaleDenominator>11300</MinScaleDenominator>
      <Name>roads trunk fill</Name>
      <ogc:Filter>
      <ogc:PropertyIsLike  wildCard="*" singleChar="." escape="!">
      <ogc:PropertyName>type</ogc:PropertyName>
      <ogc:Literal>trunk*</ogc:Literal>
        </ogc:PropertyIsLike>
    </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6d686d</CssParameter>
        <CssParameter name="stroke-width">9</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">16</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#162116</CssParameter>
        </Font>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#162116</CssParameter> </Fill>
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
      <Name>road trunk edge</Name>
      <ogc:Filter>
      <ogc:PropertyIsLike  wildCard="*" singleChar="." escape="!">
      <ogc:PropertyName>type</ogc:PropertyName>
      <ogc:Literal>trunk*</ogc:Literal>
        </ogc:PropertyIsLike>
    </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#AA8388</CssParameter>
        <CssParameter name="stroke-width">16</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>11300</MaxScaleDenominator>
      <Name>roads trunk fill</Name>
      <ogc:Filter>
      <ogc:PropertyIsLike  wildCard="*" singleChar="." escape="!">
      <ogc:PropertyName>type</ogc:PropertyName>
      <ogc:Literal>trunk*</ogc:Literal>
        </ogc:PropertyIsLike>
    </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6d686d</CssParameter>
        <CssParameter name="stroke-width">12</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">16</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#162116</CssParameter>
        </Font>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#162116</CssParameter> </Fill>
        <VendorOption name="maxDisplacement">50</VendorOption>
        <VendorOption name="repeat">300</VendorOption>
        <VendorOption name="labelAllGroup">true</VendorOption>
        <VendorOption name="removeOverlaps">true</VendorOption>
        <VendorOption name="followLine">true</VendorOption>
        <VendorOption name="group">true</VendorOption>
      </TextSymbolizer>
    </Rule> </FeatureTypeStyle>  
  
    <FeatureTypeStyle> <Rule>
      <MinScaleDenominator>272000</MinScaleDenominator>
      <Name>road motorway edge</Name>
      <ogc:Filter>
      <ogc:PropertyIsLike  wildCard="*" singleChar="." escape="!">
      <ogc:PropertyName>type</ogc:PropertyName>
      <ogc:Literal>motorway*</ogc:Literal>
        </ogc:PropertyIsLike>
    </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#AA8388</CssParameter>
        <CssParameter name="stroke-width">4</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MinScaleDenominator>272000</MinScaleDenominator>
      <Name>roads motorway fill</Name>
      <ogc:Filter>
      <ogc:PropertyIsLike  wildCard="*" singleChar="." escape="!">
      <ogc:PropertyName>type</ogc:PropertyName>
      <ogc:Literal>motorway*</ogc:Literal>
        </ogc:PropertyIsLike>
    </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6d686d</CssParameter>
        <CssParameter name="stroke-width">2</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">16</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#162116</CssParameter>
        </Font>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#162116</CssParameter> </Fill>
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
      <Name>road motorway edge</Name>
      <ogc:Filter>
      <ogc:PropertyIsLike  wildCard="*" singleChar="." escape="!">
      <ogc:PropertyName>type</ogc:PropertyName>
      <ogc:Literal>motorway*</ogc:Literal>
        </ogc:PropertyIsLike>
    </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#AA8388</CssParameter>
        <CssParameter name="stroke-width">9</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>272000</MaxScaleDenominator>
      <MinScaleDenominator>68000</MinScaleDenominator>
      <Name>roads motorway fill</Name>
      <ogc:Filter>
      <ogc:PropertyIsLike  wildCard="*" singleChar="." escape="!">
      <ogc:PropertyName>type</ogc:PropertyName>
      <ogc:Literal>motorway*</ogc:Literal>
        </ogc:PropertyIsLike>
    </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6d686d</CssParameter>
        <CssParameter name="stroke-width">6</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">16</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#162116</CssParameter>
        </Font>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#162116</CssParameter> </Fill>
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
      <Name>road motorway edge</Name>
      <ogc:Filter>
      <ogc:PropertyIsLike  wildCard="*" singleChar="." escape="!">
      <ogc:PropertyName>type</ogc:PropertyName>
      <ogc:Literal>motorway*</ogc:Literal>
        </ogc:PropertyIsLike>
    </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#AA8388</CssParameter>
        <CssParameter name="stroke-width">12</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>68000</MaxScaleDenominator>
      <MinScaleDenominator>11300</MinScaleDenominator>
      <Name>roads motorway fill</Name>
      <ogc:Filter>
      <ogc:PropertyIsLike  wildCard="*" singleChar="." escape="!">
      <ogc:PropertyName>type</ogc:PropertyName>
      <ogc:Literal>motorway*</ogc:Literal>
        </ogc:PropertyIsLike>
    </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6d686d</CssParameter>
        <CssParameter name="stroke-width">9</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">16</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#162116</CssParameter>
        </Font>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#162116</CssParameter> </Fill>
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
      <Name>road motorway edge</Name>
      <ogc:Filter>
      <ogc:PropertyIsLike  wildCard="*" singleChar="." escape="!">
      <ogc:PropertyName>type</ogc:PropertyName>
      <ogc:Literal>motorway*</ogc:Literal>
        </ogc:PropertyIsLike>
    </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#AA8388</CssParameter>
        <CssParameter name="stroke-width">16</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
      </Stroke> </LineSymbolizer>
    </Rule> </FeatureTypeStyle>
    <FeatureTypeStyle> <Rule>
      <MaxScaleDenominator>11300</MaxScaleDenominator>
      <Name>roads motorway fill</Name>
      <ogc:Filter>
      <ogc:PropertyIsLike  wildCard="*" singleChar="." escape="!">
      <ogc:PropertyName>type</ogc:PropertyName>
      <ogc:Literal>motorway*</ogc:Literal>
        </ogc:PropertyIsLike>
    </ogc:Filter>
      <LineSymbolizer> <Stroke>
        <CssParameter name="stroke">#6d686d</CssParameter>
        <CssParameter name="stroke-width">12</CssParameter>
        <CssParameter name="stroke-linejoin">round</CssParameter>
        <CssParameter name="stroke-linecap">round</CssParameter>
      </Stroke> </LineSymbolizer>
      <TextSymbolizer>
        <Label> <ogc:PropertyName>name</ogc:PropertyName> </Label>
        <Font>
          <CssParameter name="font-size">16</CssParameter>
          <CssParameter name="font-family">Arial</CssParameter>
          <CssParameter name="font-color">#162116</CssParameter>
        </Font>
        <Halo>
          <Radius> <ogc:Literal>1</ogc:Literal> </Radius>
          <Fill> <CssParameter name="fill">#dddddd</CssParameter> <CssParameter name="fill-opacity">0.85</CssParameter> </Fill>
        </Halo>
        <Fill> <CssParameter name="fill">#162116</CssParameter> </Fill>
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