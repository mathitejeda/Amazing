#include <regex>
#include "verificador.h"

bool verificador::verificarNombre(const char* nombre){
  const std::regex pattern("((\\D)+((\\')(\\D))*)+");
  return std::regex_match(nombre,pattern);
}

bool verificador::verificarDNI(const char* DNI){
  const std::regex pattern("(\\d{1,2}).(\\d{3}).(\\d{3})");
  return std::regex_match(DNI,pattern);
}

bool verificador::verificarDireccion(const char* direccion){
  const std::regex pattern("(\\w)+");
  return std::regex_match(direccion,pattern);
}
