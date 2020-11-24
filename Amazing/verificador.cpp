#include <regex>
#include "verificador.h"

bool verificador::verificarNombre(const char* nombre){
  const std::regex pattern("((\\w)+(\\')(\\w))*(\\s)*)+");
  return std::regex_match(nombre,pattern);
}

bool verificador::verificarDNI(const char* DNI){
  const std::regex pattern("((\\d{2}).(\\d{3}).(\\d{3})");
  return std::regex_match(DNI,pattern);
}