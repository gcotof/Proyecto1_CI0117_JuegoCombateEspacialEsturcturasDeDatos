#include "common.hpp"

int calcular_damage(int movimientos) {
    // Si el motor es una "Estrella de la Muerte" (Hash Set), 
    // movimientos será 1, devolviendo el daño máximo [4].
    if (movimientos <= 0) return BASE_DAMAGE; 
    
    return BASE_DAMAGE / movimientos;
}