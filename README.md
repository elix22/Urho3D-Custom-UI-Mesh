# Urho3D Custom UI Mesh

Description
-----
Custom UI mesh to convert mdl file format into UIBatch and render it using custom shaders in UI render cycle.

### Note
Only GLSL shaders supported atm. I might get around to doing HLSL later.

### Consolidating Batches
I found that consolidating batches into a single batch DID NOT increase performance: in OPENGL, vs2015.
I turned it off but you can define **CONSOLIDATE_BATCHES** at the top of UIMesh.cpp to enalbe it.

### VS2015 Release
I had trouble getting Release build to display the UIMesh properly and discovered that disabling a compile option flags solved the issue.
In *C++ -> Optimization*, set:
**Inline Function Expansion** = Any Suitable (/Ob2)

Screenshot
-----
![alt tag](https://github.com/Lumak/Urho3D-Custom-UI-Mesh/blob/master/screenshot/uimesh.gif)

Thanks To
-----
JTippetts for his *Diablo 3 Resource Bubble* resource. His resource is the best looking thing in this demo.
His resource can be found here - https://github.com/JTippetts/D3ResourceBubbles

Simon Schreibt for his plethora of VFX resources. The Diablo 3 Bubble and the Rime Fire VFX blog can be found at https://simonschreibt.de/


To Build
-----
To build it, unzip/drop the repository into your Urho3D/ folder and build it the same way as you'd build the default Samples that come with Urho3D.
**Built with Urho3D 1.7 tag.**

License
-----
The MIT License (MIT)







