cmake_minimum_required(VERSION 3.8)

add_library(ImGuiNodeEditor)
add_library(ImGuiNodeEditor::ImGuiNodeEditor ALIAS ImGuiNodeEditor)
target_compile_features(ImGuiNodeEditor PUBLIC cxx_std_17)

# ---Add source files---
target_sources(ImGuiNodeEditor PRIVATE
    crude_json.cpp
    imgui_canvas.cpp
    imgui_node_editor_api.cpp
    imgui_node_editor.cpp)