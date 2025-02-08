#include "combat_medic.h"

void combat_medic_heal(Unit *self, Unit *target)
{
    if (unit_get_health(target) < 0)
    {
        printf("He is gone...");
    }
    else
    {
        printf("Hang in there!");
        unit_set_health(target, unit_get_health(target) + 10);
    }
}

/*void make_combat_medic(CombatMedic *self, int health, int damage)
{
    make_soldier(&self->inherited, health, damage);
    self->inherited.inherited.vt->heal_target = combat_medic_heal;
}*/
void make_combat_medic(CombatMedic *self, int health, int damage)
{
    make_soldier(&self->inherited, health, damage);

    // Ensure CombatMedic has its own VTable
    self->inherited.inherited.vt = malloc(sizeof(UnitVTable));
    memcpy(self->inherited.inherited.vt, self->inherited.vt, sizeof(UnitVTable));
    self->inherited.inherited.vt->heal_target = combat_medic_heal; // Override heal method
}
