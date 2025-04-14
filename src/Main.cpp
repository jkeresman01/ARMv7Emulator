#include "App/Emulator.h"

int main() 
{
    armv7emulator::EmulatorARMv7 emultorARMv7;

    emultorARMv7.Init();
    emultorARMv7.Run();
    emultorARMv7.Shutdown();
}
