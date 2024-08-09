# 42_cpp03

In this module we will practice inheritance.  For this we will create a base class called TrapClap and then we will have a ScavTrap and Fragatrap and battle the diamond problem in DiamondTrap!   
(look up the video game Borderlands to know more about the characters, these are iconic robots known for their unique personalities and combat abilities).



## ex00
Creating a ClapTrap base class I initially set his properties to private 

## ex01
This exercise will ask for a ScavTrap class that inherits from ClapTrap.  I will set the properties to protected and create a constructor that will call the ClapTrap constructor.  The ScavTrap will also have an own function `guardGate`. The point is that ScavTrap will start by calling the ClapTrap constructor and then the ScavTrap constructor.  The destructors will be called in the reverse order.  
What I want to see is that the order of constructor and destructor is correct.  
It should be:
```cpp
ClapTrap constructor called
ScavTrap constructor called
ScavTrap destructor called
ClapTrap destructor called
```
Also, when writing the ScavTrap class I will not need to declare the attributes name, hitPoints, energyPoints and attackamage again since they are inherited. Same for the methods... but attack should print something different so it will be reimplemented.

In the copy constructor I will also call the ClapTrap copy constructor first.


## ex02
Another inherited class, Fragtrap.

## ex03
Now we get to the heart of the matter with the diamond problem.
We create a DiamondTrap which inherit from both the ScavTrap and FragTrap. Of course they inherit from ClapTrap so will the constructor for ClapTrap be created twice?  

The Diamond Problem is a common issue that arises in object-oriented 
programming languages that support multiple inheritance. 
It's named after the shape of the class diagram that illustrates 
the problem, which looks like a diamond.
  	A
   / \
  B   C
   \ /
    D

In the diagram above, class D inherits from both B and C.
If B and C have a member function with the same name,
which one does D inherit?
C++ allows multiple inheritance but it has its own way of solving the 
diamond problem: through the use of virtual inheritance. 
By declaring the inheritance from A to B and C as virtual, 
C++ ensures that only one copy of A's members is included in D. 
This means that there's only one possible implementation of the method in D, 
which avoids the ambiguity.
To avoid this we use virtual inheritance:
```cpp
class ClapTrap {
    // ...
};

class FragTrap : virtual public ClapTrap {
    // ...
};

class ScavTrap : virtual public ClapTrap {
    // ...
};

class DiamondTrap : public ScavTrap, public FragTrap {
    // ...
};
```
Virtual inheritance ensures that there's only one instance of the base class in the derived class hierarchy. The compiler introduces a virtual pointer in derived classes to manage the base class subobject. There is only one base class created in DiamondTrap.
Performance overhead: Virtual inheritance can introduce some performance overhead due to the additional complexity of managing the virtual pointer.
Always declare the destructor as virtual in the base class when using virtual inheritance to ensure proper object destruction.

## links
