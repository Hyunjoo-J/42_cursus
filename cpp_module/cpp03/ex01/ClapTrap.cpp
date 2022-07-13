#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "ClapTrap Default construct called\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name),  _hit_point(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "ClapTrap construct (" << name << ") called\n";
}

ClapTrap::ClapTrap(const ClapTrap& ref)
{
	std::cout << "ClapTrap copy constructor (" << ref.getName() << ") called\n";
	this->_name = ref.getName();
	this->_hit_point = ref.getHitPoint();
	this->_energy_point = ref.getEnergyPoint();
	this->_attack_damage = ref.getAttackDamage();
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref)
{
	std::cout << "ClapTrap operator '=' (" << ref.getName() << ") called\n";
	this->_name = ref.getName();
	this->_hit_point = ref.getHitPoint();
	this->_energy_point = ref.getEnergyPoint();
	this->_attack_damage = ref.getAttackDamage();
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor (" << this->getName() << ") called\n";
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hit_point < 1)
	{
		std::cout << "ClapTrap " << this->getName() << " has no hit point anymore. It was dead\n";
		return ;
	}
	if (this->_energy_point < 1)
	{
		std::cout << "ClapTrap " << this->getName() << " has no energy point anymore.\n";
		return ;
	}
	std::cout << "ClapTrap " << this->getName() << " ";
	std::cout << "attacks " << target << ", ";
	std::cout << "causing " << this->_attack_damage << " ";
	std::cout << "hit points of damage!\n";
	this->_energy_point -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_point < 1)
	{
		std::cout << "ClapTrap " << this->getName() << " has no hit point anymore. It was dead\n";
		return ;
	}
	if (this->_hit_point <= amount)
	{
		std::cout << "ClapTrap " << this->getName() << " takes damage and loses all hit points.. and now it is dead\n";
		this->_hit_point = 0;
	}
	else
	{
		std::cout << "ClapTrap " << this->getName() << " takes damage so lose " << amount << " hit points..\n";
		this->_hit_point -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_point < 1)
	{
		std::cout << "ClapTrap " << this->getName() << " has no hit point anymore. It was dead\n";
		return ;
	}
	if (this->_energy_point < 1)
	{
		std::cout << "ClapTrap " << this->getName() << "has no energy points anymore.\n";
		return ;
	}
	if (this->_hit_point == 10)
	{
		std::cout << "ClapTrap " << this->getName() << "'s hit point is full.\n";
	}
	else
	{
		std::cout << "ClapTrap " << this->getName() << " repairs itself, so get " << amount << " hit points!";
		if (this->_hit_point + amount >= 10)
		{
			std::cout << " And now it has full hit points.\n";
			this->_hit_point = 10;
		}
		else
		{
			std::cout << std::endl;
			this->_hit_point += amount;
		}
		this->_energy_point -= 1;
	}
}

std::string ClapTrap::getName() const
{
	return this->_name;
}

unsigned int ClapTrap::getHitPoint() const
{
	return this->_hit_point;
}

unsigned int ClapTrap::getEnergyPoint() const
{
	return this->_energy_point;
}

unsigned int ClapTrap::getAttackDamage() const
{
	return this->_attack_damage;
}