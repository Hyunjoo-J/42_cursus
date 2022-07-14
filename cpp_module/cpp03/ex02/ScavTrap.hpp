#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
public:
	ScavTrap();
	ScavTrap(const ScavTrap &ref);
	ScavTrap& operator=(const ScavTrap& ref);
	virtual ~ScavTrap();

	ScavTrap(std::string _name);

	virtual void attack(const std::string& target);
	void guardGate();
};

#endif
