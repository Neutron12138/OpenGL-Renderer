@echo off

echo ----------Compling----------
g++ -finput-charset=utf-8 -fexec-charset=gbk "../gl_renderer/dll_main.cpp"^
    -o "gl_renderer.dll" -shared -L. -lgl_wrapper -DGL_RENDERER_INCLUDE_STB_IMPL

echo ----------End----------
pause
