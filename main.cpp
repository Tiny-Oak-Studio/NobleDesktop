#include <memory>
#include <fstream>
#include <filesystem>
#include "NobleDesktop.h"
#include "../NobleVM/VirtualMachine.h"

Noble::VM::Frame LoadFrame(const std::string& frameName)
{
    Noble::VM::Frame frame;
    if (std::ifstream opsFile(frameName + ".naf"); opsFile.is_open())
    {
        std::filesystem::path opsPath { frameName + ".naf" };
        ulong opsSize = file_size(opsPath);

        opsFile.read(reinterpret_cast<std::ifstream::char_type*>(&frame.ops), opsSize);
        frame.numOps = opsSize;
    }

    if (std::ifstream constantsFile(frameName + ".ndf"); constantsFile.is_open())
    {
        std::filesystem::path dataPath { frameName + ".ndf" };
        ulong dataSize = file_size(dataPath);

        constantsFile.read(reinterpret_cast<std::ifstream::char_type*>(&frame.constants), dataSize);
        frame.numConstants = dataSize;
    }
    return frame;
}

int main(int argc, char** argv)
{
    const std::unique_ptr<Noble::VM::VirtualMachineGraphics> graphics = std::make_unique<Noble::Desktop::NobleDesktop>();
    Noble::VM::VirtualMachine virtualMachine(graphics.get());

    Noble::VM::Frame frame = LoadFrame("test");
    virtualMachine.RunFrame(frame);

    return 0;
}