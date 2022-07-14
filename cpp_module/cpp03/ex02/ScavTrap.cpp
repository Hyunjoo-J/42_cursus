#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor called with " << name << std::endl;
	this->_name = name;
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_name = "Default";
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called with " << this->getName() << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ref)
{
	std::cout << "ScavTrap copy constructor called" << ref.getName() << std::endl;
	this->_name = ref.getName();
	this->_hit_point = ref.getHitPoint();
	this->_energy_point = ref.getEnergyPoint();
	this->_attack_damage = ref.getAttackDamage();
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ref)
{
	std::cout << "ScavTrap copy assignment operator called" << ref.getName() << std::endl;
	this->_name = ref.getName();
	this->_hit_point = ref.getHitPoint();
	this->_energy_point = ref.getEnergyPoint();
	this->_attack_damage = ref.getAttackDamage();
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hit_point < 1)
	{
		std::cout << "ScavTrap do not have hit points anymore." << std::endl;
		return ;
	}
	if (this->_energy_point < 1)
	{
		std::cout << "ScavTrap do not have energy points anymore." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " ";
	std::cout << "attacks " << target << ", ";
	std::cout << "causing " << this->_attack_damage << " ";
	std::cout << "hit points of damage!" << std::endl;
	this->_energy_point -= 1;
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}
