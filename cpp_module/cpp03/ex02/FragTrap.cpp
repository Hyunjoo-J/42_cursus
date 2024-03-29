

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap constructor called with " << name << std::endl;
	this->_name = name;
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_name = "Default";
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called with " << this->getName() << std::endl;
}

FragTrap::FragTrap(const FragTrap& ref)
{
	std::cout << "FragTrap copy constructor called with " << ref.getName() << std::endl;
	this->_name = ref.getName();
	this->_hit_point = ref.getHitPoint();
	this->_energy_point = ref.getEnergyPoint();
	this->_attack_damage = ref.getAttackDamage();
}

FragTrap& FragTrap::operator=(const FragTrap& ref)
{
	std::cout << "FragTrap copy assignment operator called with " << ref.getName() << std::endl;
	this->_name = ref.getName();
	this->_hit_point = ref.getHitPoint();
	this->_energy_point = ref.getEnergyPoint();
	this->_attack_damage = ref.getAttackDamage();
	return (*this);
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " HIGH FIVES!" << std::endl;
}
