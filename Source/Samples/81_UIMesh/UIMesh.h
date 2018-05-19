//
// Copyright (c) 2008-2017 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#pragma once
#include <Urho3D/UI/UIElement.h>

using namespace Urho3D;
namespace Urho3D
{
class Material;
class Graphics;
}

//=============================================================================
//=============================================================================
class UIMesh : public UIElement
{
    URHO3D_OBJECT(UIMesh, UIElement);
public:

    UIMesh(Context* context);
    virtual ~UIMesh();
    static void RegisterObject(Context* context);

    void SetModel(const String& modelFilepath, const String& textureFilename=String::EMPTY);
    void SetMaterial(const String &matrialFilename);
    void SetBlendMode(BlendMode blendMode);

    virtual void Update(float timeStep);
    virtual void GetBatches(PODVector<UIBatch>& batches, PODVector<float>& vertexData, const IntRect& currentScissor);
    virtual void Render(Graphics* graphics, const UIBatch& batch);

    void SetSize(const IntVector2& size);
    void SetSize(int width, int height);
    void SetPosition(const IntVector2& position);
    void SetPosition(int x, int y);

    void SetEnableBubbleEffect(bool enable){ bubbleEffect_ = enable; }
    void SetScrollUV(bool enable, const Vector2 &uvScrollRate)
    {
        scrollUV_ = enable;
        scrollRate_ = uvScrollRate;
    }
    void SetFixedUV(bool enable, const Vector2 &fixedRate)
    {
        fixedUV_ = enable;
        fixedRate_ = fixedRate;
        workingFixedRate_ = fixedRate;
    }

protected:
    void UpdateMaterialShader(Graphics* graphics);
    void UpdateScissors();
    void UpdateBlendMode();
    void UpdateScrollUV();
    void UpdateFixedUV();

protected:
    PODVector<UIBatch>  batches_;
    PODVector<float>    workingVertexData_;
    PODVector<float>    vertexData_;
    SharedPtr<Texture>  texture_;
    SharedPtr<Material> material_;
    BlendMode           blendMode_;

    bool bubbleEffect_;
    float dir_;
    float level_;

    bool scrollUV_;
    Vector2 scrollRate_;

    bool fixedUV_;
    Vector2 fixedRate_;
    Vector2 workingFixedRate_;
    unsigned fixedInterval_;
    Timer fixedIntervalTimer_;
};

