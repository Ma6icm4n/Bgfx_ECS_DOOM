#include <stdio.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>

#include "Gravity.h"
#include "RigidBody.h"
#include "Transform.h"
#include "Renderable.h"
#include "Coordinator.h"
#include "PhysicSystem.h"
#include "RenderSystem.h"
#include "ControlSystem.h"
#include "Camera.h"
#include "Time.h"
#include <chrono>
#include <random>

#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "bx/math.h"
#include "GLFW/glfw3.h"
#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW/glfw3native.h"

#include "Window.h"

#define WIND_WIDTH 1600
#define WIND_HEIGHT 900


Coordinator gCoordinator;
static bool quit = false;

void QuitHandler(Event& event) {
    quit = true;
}

int main(void) {


    gCoordinator.Init();

    Window window;
    window.Init("DOOM-ECS", WIND_WIDTH, WIND_HEIGHT, 0, 0);

    gCoordinator.AddEventListener(FUNCTION_LISTENER(Events::Window::QUIT, QuitHandler));

    gCoordinator.RegisterComponent<Gravity>();
    gCoordinator.RegisterComponent<RigidBody>();
    gCoordinator.RegisterComponent<Transform>();
    gCoordinator.RegisterComponent<Renderable>();
    gCoordinator.RegisterComponent<Camera>();

    auto physicsSystem = gCoordinator.RegisterSystem<PhysicsSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<Gravity>());
        signature.set(gCoordinator.GetComponentType<RigidBody>());
        signature.set(gCoordinator.GetComponentType<Transform>());
        gCoordinator.SetSystemSignature<PhysicsSystem>(signature);
    }

    physicsSystem->Init();
    
    auto renderSystem = gCoordinator.RegisterSystem<RenderSystem>();
    {
        Signature signature;
        //signature.set(gCoordinator.GetComponentType<Renderable>());
        signature.set(gCoordinator.GetComponentType<Transform>());
        gCoordinator.SetSystemSignature<RenderSystem>(signature);
    }
    renderSystem->Init();

    auto controlSystem = gCoordinator.RegisterSystem<ControlSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<Camera>());
        signature.set(gCoordinator.GetComponentType<Transform>());
        gCoordinator.SetSystemSignature<ControlSystem>(signature);
    }
    controlSystem->Init();
    
    std::vector<Entity> entities(MAX_ENTITIES - 1);

    std::default_random_engine generator;
    std::uniform_real_distribution<float> randPosition(-10.0f, 20.0f);
    std::uniform_real_distribution<float> randRotation(0.0f, 3.0f);
    std::uniform_real_distribution<float> randScale(3.0f, 5.0f);
    std::uniform_real_distribution<float> randColor(0.0f, 1.0f);
    std::uniform_real_distribution<float> randGravity(-0.5f, -0.1f);

    float scale = randScale(generator);

    

    for(auto & entity : entities) {
        entity = gCoordinator.CreateEntity();

        float gravity[3] = { 0.0f, randGravity(generator), 0.0f };
        gCoordinator.AddComponent(entity, Gravity{ 0.0f, gravity[1] });

        float basevelocity[3] = { 0.0f, 0.0f, 0.0f };
        float baseacceleration[3] = { 0.0f, 0.0f, 0.0f };
        gCoordinator.AddComponent(entity,
             RigidBody{
                *basevelocity,
                *baseacceleration
            }
        );

        float baseposition[3] = { randPosition(generator), randPosition(generator), randPosition(generator) };
        float baserotation[3] = { randRotation(generator), randRotation(generator), randRotation(generator) };
        float basescale[3] = { scale, scale, scale };
        gCoordinator.AddComponent(entity,
            Transform{
                baseposition[0], baseposition[1], baseposition[2],
                baserotation[0],baserotation[1], baserotation[2],
                basescale[0], basescale[1], basescale[2]
            }
         );

    }
    
    float time = Time::getTime();
    while (!quit) {

        float time = Time::getTime();

        const bx::Vec3 at = { 0.0f, 0.0f,  0.0f };
        const bx::Vec3 eye = { 10.0f, 30.0f, -80.0f };
        float view[16];
        bx::mtxLookAt(view, eye, at);
        float proj[16];
        bx::mtxProj(proj, 60.0f, float(WIND_WIDTH) / float(WIND_HEIGHT), 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);
        bgfx::setViewTransform(0, view, proj);

        unsigned int input = window.ProcessEvents();
        controlSystem->Update(time, input);
        physicsSystem->Update(time);
        renderSystem->Update(time);

        window.Update();

        bgfx::frame();

    }

    renderSystem->Destroy();
    bgfx::shutdown();
    window.Shutdown();
    glfwTerminate();

    return 0;
}

