#include "Uniforms.glsl"
#include "Samplers.glsl"
#include "Transform.glsl"
#include "ScreenPos.glsl"
#include "Fog.glsl"

varying vec2 vTexCoord;
varying vec4 vWorldPos;

uniform vec2 cSpeedA;
uniform vec2 cSpeedB;

#ifdef VERTEXCOLOR
    varying vec4 vColor;
#endif

void VS()
{
    mat4 modelMatrix = iModelMatrix;
    vec3 worldPos = GetWorldPos(modelMatrix);
    gl_Position = GetClipPos(worldPos);
    vTexCoord = GetTexCoord(iTexCoord);
    vWorldPos = vec4(worldPos, GetDepth(gl_Position));

    #ifdef VERTEXCOLOR
        vColor = iColor;
    #endif
}

void PS()
{
    vec4 circMask = texture2D(sDiffMap, vTexCoord);
    if (circMask.r < 0.5)
        discard;

    vec2 texCoordA = vTexCoord * 0.5 + cElapsedTimePS * cSpeedA;
    vec2 texCoordB = vTexCoord * 1.5 + cElapsedTimePS * cSpeedB;
    vec4 noiseMask1 = texture2D(sEmissiveMap, texCoordA);
    vec4 noiseMask2 = texture2D(sEmissiveMap, texCoordB);
    vec4 combMask = noiseMask1 * noiseMask2 * 2.0;

    vec4 specColor = texture2D(sSpecMap, vTexCoord);
    vec4 diffColor = combMask * (cMatDiffColor + vec4(1.0, 1.0, 1.0, 1.0) * specColor.a * 2.0);

    #ifdef ALPHAMASK // not used
        if (diffColor.a < 0.5)
            discard;
    #endif

    #ifdef VERTEXCOLOR
        diffColor *= vColor;
    #endif

    gl_FragColor = diffColor;
}
