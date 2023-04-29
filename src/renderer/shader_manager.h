#pragma once

#include <string>

namespace eightthreeegnine {
class Shader {
public:
    unsigned int ID;

    Shader();
    void init(const char* vertexPath, const char* fragmentPath);
    void use();
        // utility uniform functions
    void setBool(const std::string &name, bool value) const;  
    void setInt(const std::string &name, int value) const;   
    void setFloat(const std::string &name, float value) const;
private:
    void checkCompileErrors(unsigned int shader, std::string type);
};
} // namespace eightthreeegnine