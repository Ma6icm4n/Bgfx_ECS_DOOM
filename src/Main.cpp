#include <iostream>
#include <fstream>
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

    auto controlSystem = gCoordinator.RegisterSystem<ControlSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<Transform>());
        signature.set(gCoordinator.GetComponentType<Camera>());
        gCoordinator.SetSystemSignature<ControlSystem>(signature);
    }
    controlSystem->Init();

    auto renderSystem = gCoordinator.RegisterSystem<RenderSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<Renderable>());
        signature.set(gCoordinator.GetComponentType<Transform>());
        gCoordinator.SetSystemSignature<RenderSystem>(signature);
    }
    renderSystem->Init();



    std::vector<Entity> entities(MAX_ENTITIES - 1);

    std::default_random_engine generator;
    std::uniform_real_distribution<float> randPosition(-60.0f, 20.0f);
    std::uniform_real_distribution<float> randRotation(0.0f, 3.0f);
    std::uniform_real_distribution<float> randScale(3.0f, 5.0f);
    std::uniform_real_distribution<float> randColor(0.0f, 1.0f);
    std::uniform_real_distribution<float> randGravity(-0.5f, -0.1f);

    float scale = randScale(generator);


    //######################## LEVEL LOADER #######################
    std::ifstream file("../../assets/level.txt");
    if (!file) {
        std::cout << "File not found" << '\n';
        std::cout << "../assets/level.h" << '\n';

        return 0;
    }

    float nbRow = 0;
    float nbColumn = 0;
    std::string line;

    while (std::getline(file, line)) {
        std::cout << "line" << " " << std::to_string(nbRow) << "\n";

        for (std::string::iterator it = line.begin(); it != line.end(); ++it) {
            std::cout << nbColumn << "\n";

            switch (*it) {
                case 'X':
                {
                    Entity wall = gCoordinator.CreateEntity();
                    float basevelocity[3] = { 0.0f, 0.0f, 0.0f };
                    float baseacceleration[3] = { 0.0f, 0.0f, 0.0f };
                    gCoordinator.AddComponent(wall,
                        RigidBody{
                           *basevelocity,
                           *baseacceleration
                        }
                    );

                    float baseposition[3] = { nbColumn *2 , 0.0f, nbRow *2 };
                    float baserotation[3] = { 0.0f, 0.0f, 0.0f };
                    float basescale[3] = { 1.0f, 2.0f, 1.0f };
                    gCoordinator.AddComponent(wall,
                        Transform{
                            baseposition[0], baseposition[1], baseposition[2],
                            baserotation[0],baserotation[1], baserotation[2],
                            basescale[0], basescale[1], basescale[2]
                        }
                    );

                    gCoordinator.AddComponent(wall, Renderable{ 0.0f, 0.0f, 0.0f });



                    Entity wall2 = gCoordinator.CreateEntity();
                    float basevelocity2[3] = { 0.0f, 0.0f, 0.0f };
                    float baseacceleration2[3] = { 0.0f, 0.0f, 0.0f };
                    gCoordinator.AddComponent(wall2,
                        RigidBody{
                           *basevelocity2,
                           *baseacceleration2
                        }
                    );

                    float baseposition2[3] = { nbColumn * 2 , 0.20f, nbRow * 2 };
                    float baserotation2[3] = { 0.0f, 0.0f, 0.0f };
                    float basescale2[3] = { 1.0f, 2.0f, 1.0f };
                    gCoordinator.AddComponent(wall2,
                        Transform{
                            baseposition2[0], baseposition2[1], baseposition2[2],
                            baserotation2[0],baserotation2[1], baserotation2[2],
                            basescale2[0], basescale2[1], basescale2[2]
                        }
                    );

                    gCoordinator.AddComponent(wall2, Renderable{ 0.0f, 0.0f, 0.0f });
                }
                break;

                case '/':
                {
                    Entity floor = gCoordinator.CreateEntity();
                    float basevelocity[3] = { 0.0f, 0.0f, 0.0f };
                    float baseacceleration[3] = { 0.0f, 0.0f, 0.0f };
                    gCoordinator.AddComponent(floor,
                        RigidBody{
                           *basevelocity,
                           *baseacceleration
                        }
                    );

                    float baseposition[3] = { nbColumn * 2, -0.20f, nbRow * 2};
                    float baserotation[3] = { 0.0f, 0.0f, 0.0f };
                    float basescale[3] = { 1.0f, 1.0f, 1.0f };
                    gCoordinator.AddComponent(floor,
                        Transform{
                            baseposition[0], baseposition[1], baseposition[2],
                            baserotation[0],baserotation[1], baserotation[2],
                            basescale[0], basescale[1], basescale[2]
                        }
                    );

                    gCoordinator.AddComponent(floor, Renderable{ 0.0f, 0.0f, 0.0f });
                }
                break;
            }
            ++nbColumn;
        }
        std::cout << "\n";
        ++nbRow;

        nbColumn = 0;
    }
        /*
        for(auto & entity : entities) {


            entity = gCoordinator.CreateEntity();

            float gravity[3] = { 0.0f, randGravity(generator), 0.0f };
            //gCoordinator.AddComponent<Gravity>(entity, Gravity{ 0.0f, gravity[1] });

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

            gCoordinator.AddComponent(entity, Renderable{ 0.0f, 0.0f, 0.0f });

        }*/

    float time = Time::getTime();
    double xpos, ypos;
    while (!quit) {

        float time = Time::getTime();

        unsigned int input = window.ProcessEvents(xpos, ypos);
        controlSystem->Update(input, xpos, ypos);

        renderSystem->Update(time);
        physicsSystem->Update(time);


        window.Update();

        bgfx::frame();

    }

    renderSystem->Destroy();
    bgfx::shutdown();
    window.Shutdown();
    glfwTerminate();

    return 0;
}

