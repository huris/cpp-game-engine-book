﻿//
// Created by captainchen on 2022/6/6.
//

#include "light.h"
#include <rttr/registration>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>
#include <glm/gtx/euler_angles.hpp>
#include "component/game_object.h"
#include "component/transform.h"
#include "renderer/mesh_renderer.h"
#include "renderer/material.h"
#include "render_device/uniform_buffer_object_manager.h"

using namespace rttr;
RTTR_REGISTRATION//注册反射
{
    registration::class_<Light>("Light")
            .constructor<>()(rttr::policy::ctor::as_raw_ptr);
}

Light::Light():Component() {}

Light::~Light() {}

void Light::set_color(glm::vec3 color){
    color_ = color;
    UniformBufferObjectManager::UpdateUniformBlockSubData3f("Light","u_light_color",color_);
};

void Light::set_intensity(float intensity){
    intensity_ = intensity;
    UniformBufferObjectManager::UpdateUniformBlockSubData1f("Light","u_light_intensity",intensity_);
};