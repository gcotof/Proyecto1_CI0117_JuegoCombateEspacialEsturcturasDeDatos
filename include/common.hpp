#ifndef COMMON_HPP
#define COMMON_HPP

// Constante base sugerida en clase (ej. 10,000)
const int BASE_DAMAGE = 10000; 

/**
 * Calcula el daño basado en la eficiencia de la búsqueda.
 * A menos movimientos (motores rápidos como Hash), más daño.
 */
int calcular_damage(int movimientos);

#endif