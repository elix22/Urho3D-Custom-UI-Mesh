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

#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Graphics/Zone.h>
#include <Urho3D/UI/Button.h>
#include <Urho3D/UI/Font.h>
#include <Urho3D/UI/Text.h>
#include <Urho3D/UI/UIEvents.h>

#include "UICustomDemo.h"
#include "UIMesh.h"

#include <Urho3D/DebugNew.h>
//=============================================================================
//=============================================================================
URHO3D_DEFINE_APPLICATION_MAIN(UICustomDemo)

UICustomDemo::UICustomDemo(Context* context)
    : Sample(context)
{
    UIMesh::RegisterObject(context);
}

void UICustomDemo::Setup()
{
    engineParameters_["WindowTitle"]   = GetTypeName();
    engineParameters_["LogName"]       = GetSubsystem<FileSystem>()->GetProgramDir() + "customUI.log";
    engineParameters_["FullScreen"]    = false;
    engineParameters_["Headless"]      = false;
    engineParameters_["WindowWidth"]   = 1280; 
    engineParameters_["WindowHeight"]  = 720;
    engineParameters_["ResourcePaths"] = "Data;CoreData;Data/CustomUI;";
}

void UICustomDemo::Start()
{
    Sample::Start();

    CreateUIMesh();

    ChangeDebugHudText();
}

void UICustomDemo::CreateUIMesh()
{
    // change background color
    GetSubsystem<Renderer>()->GetDefaultZone()->SetFogColor(Color(0.1f, 0.1f, 0.14f));
    ResourceCache* cache = GetSubsystem<ResourceCache>();
    UIElement* uiRoot = GetSubsystem<UI>()->GetRoot();

    uiRoot->SetDefaultStyle(cache->GetResource<XMLFile>("UI/DefaultStyle.xml"));

    UIMesh *uiMesh = new UIMesh(context_);
    uiMesh->SetModel("Models/Plane.mdl");
    uiMesh->SetMaterial("Materials/resourcebubble.xml");
    uiMesh->SetSize(200, 200);
    uiMesh->SetPosition(100, 40);
    uiMesh->SetEnableBubbleEffect(true);
    uiRoot->AddChild(uiMesh);

    uiMesh = new UIMesh(context_);
    uiMesh->SetModel("Models/Plane.mdl");
    uiMesh->SetMaterial("Materials/UIBackground.xml");
    uiMesh->SetSize(200, 200);
    uiMesh->SetPosition(IntVector2(350, 40));
    uiRoot->AddChild(uiMesh);

    uiMesh = new UIMesh(context_);
    uiMesh->SetModel("Models/Plane.mdl");
    uiMesh->SetMaterial("Materials/UIFire.xml");
    uiMesh->SetBlendMode(BLEND_ADDALPHA);
    uiMesh->SetSize(200, 200);
    uiMesh->SetPosition(IntVector2(600, 40));
    uiMesh->SetPriority(1);
    uiRoot->AddChild(uiMesh);

    uiMesh = new UIMesh(context_);
    uiMesh->SetModel("Models/Plane.mdl");
    uiMesh->SetMaterial("Materials/UIRimeFire.xml");
    uiMesh->SetBlendMode(BLEND_ADDALPHA);
    uiMesh->SetSize(200, 200);
    uiMesh->SetPosition(IntVector2(850, 40));
    uiMesh->SetPriority(1);
    uiRoot->AddChild(uiMesh);

    uiMesh = new UIMesh(context_);
    uiMesh->SetModel("Models/uiWheel2.mdl", "Textures/uiWheelcolHalfVert.png");
    uiMesh->SetSize(200, 200);
    uiMesh->SetPosition(IntVector2(100, 290));
    uiMesh->SetScrollUV(true, Vector2(0.002f, 0.0f));
    uiRoot->AddChild(uiMesh);

    uiMesh = new UIMesh(context_);
    uiMesh->SetModel("Models/uiWheel1.mdl", "Textures/colorCloud.png");
    uiMesh->SetSize(200, 200);
    uiMesh->SetPosition(IntVector2(350, 290));
    uiMesh->SetScrollUV(true, Vector2(0.003f, -0.004f));
    uiRoot->AddChild(uiMesh);

    uiMesh = new UIMesh(context_);
    uiMesh->SetModel("Models/uiWheel1.mdl");
    uiMesh->SetMaterial("Materials/UISelectWheel.xml");
    uiMesh->SetSize(200, 200);
    uiMesh->SetPosition(IntVector2(600, 290));
    uiMesh->SetFixedUV(true, Vector2(0.2f, 0.00f));
    uiRoot->AddChild(uiMesh);
}

void UICustomDemo::ChangeDebugHudText()
{
    // change profiler text
    if (GetSubsystem<DebugHud>())
    {
        Text *dbgText = GetSubsystem<DebugHud>()->GetProfilerText();
        dbgText->SetColor(Color::CYAN);
        dbgText->SetTextEffect(TE_NONE);

        dbgText = GetSubsystem<DebugHud>()->GetStatsText();
        dbgText->SetColor(Color::CYAN);
        dbgText->SetTextEffect(TE_NONE);

        dbgText = GetSubsystem<DebugHud>()->GetMemoryText();
        dbgText->SetColor(Color::CYAN);
        dbgText->SetTextEffect(TE_NONE);

        dbgText = GetSubsystem<DebugHud>()->GetModeText();
        dbgText->SetColor(Color::CYAN);
        dbgText->SetTextEffect(TE_NONE);
    }
}


