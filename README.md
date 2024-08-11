# 42_cpp03

In this module, we will practice inheritance. For this, we will create a base class called TrapClap. Then, we will have a ScavTrap and FragTrap, and a battle for the diamond problem in DiamondTrap! (Look up the video game Borderlands to know more about the characters. These are iconic robots known for their unique personalities and combat abilities).

## Initializer Lists vs. Assignment in Copy Constructors
Understanding the Difference

Initializer lists are generally preferred over assignment within constructors for several reasons:

- Efficiency: Initializer lists directly initialize members, avoiding unnecessary default construction and subsequent assignment.
- Correctness: For members with no default constructors (e.g., const members or members of classes without default constructors), initializer lists are mandatory.
- Clarity: Explicitly initializing members in the initializer list improves code readability and maintainability.

Example of an initializer list:
```cpp
ClapTrap::ClapTrap( void ) : name("anon claptrap"), hitPoints(10), energyPoints(10), attackDamage(0) {
	debug("ClapTrap default constructor called");
}
```
The above is considered better than:
```cpp
ClapTrap::ClapTrap(const ClapTrap& copy) {
	*this = copy;
	// print copy constructor message
}
```

In the first example, the ClapTrap base class is initialized first using the base class copy constructor, followed by the initialization of energyPoints and attackDamage members.
ex
```cpp


### A caveat
So you now think that you can use initializer lists everywhere, right? Not quite. In the derived class constructor for instance they would not work on inherited members. For those you still need to assign then in the constructor body.  
```cpp
ScavTrap::ScavTrap( std::string const name ): ClapTrap(name) {
	energyPoints = 50;
	attackDamage = 20;
	debug("ScavTrap constructor called");
}
```

### Can I have a const name?
lets do it, try it! If I put my name as const in the constructor, it will break the assignment operator in cpp98.

## New flags in my makefile

- `-Wshadow` This flag is used to warn whenever a local variable shadows another local variable, parameter, or global variable. This flag is useful in preventing bugs that can be introduced by shadowing.
- `-Wconversion` This flag is used to warn for implicit conversions that may alter a value. This includes conversions between real and integer, like int to float, or pointer to int. It also warns for conversions between signed and unsigned integers. Note that this warning is on by default in C++.
- `-Wunreachable-code` This flag is used to warn when the compiler detects that code will never be executed. 

## Virtual destructor

### When to Declare a Virtual Destructor

A virtual destructor should be declared in the base class of a polymorphic class hierarchy. This ensures that the correct destructor is called when deleting a derived class object through a base class pointer.

Ex
```cpp
class Base {
public:
    virtual ~Base() { std::cout << "Base destructor called\n"; }
};

class Derived : public Base {
public:
    ~Derived() override { std::cout << "Derived destructor called\n"; }
};

int main() {
    Base* ptr = new Derived();
    delete ptr; // Correctly calls both Derived and Base destructors
}

```

## Virtual Destructors in Diamond Inheritance

In a diamond inheritance scenario with virtual inheritance, only the base class needs to have a virtual destructor.

ex
```cpp
class ClapTrap {
public:
    virtual ~ClapTrap() { std::cout << "ClapTrap destructor called\n"; }
    // ...
};

class FragTrap : virtual public ClapTrap {
public:
    // ~FragTrap() { std::cout << "FragTrap destructor called\n"; } // Optional
    // ...
};

class ScavTrap : virtual public ClapTrap {
public:
    // ~ScavTrap() { std::cout << "ScavTrap destructor called\n"; } // Optional
    // ...
};

class DiamondTrap : public FragTrap, public ScavTrap {
public:
    ~DiamondTrap() { std::cout << "DiamondTrap destructor called\n"; }
    // ...
};
```


# The assignments
## ex00
Creating a ClapTrap base class. Initially, I set its properties to private.

## ex01
This exercise will ask for a ScavTrap class that inherits from ClapTrap. I will set the properties to protected and create a constructor that will call the ClapTrap constructor. The ScavTrap will also have its own function called `guardGate`. The point is that ScavTrap will start by calling the ClapTrap constructor and then the ScavTrap constructor. The destructors will be called in the reverse order.  
What I want to see is that the order of the constructor and destructor is correct.  
It should be:
```cpp
ClapTrap constructor called
ScavTrap constructor called
ScavTrap destructor called
ClapTrap destructor called
```
Also, when writing the ScavTrap class, I will not need to declare the attributes name, hitPoints, energyPoints, and attackDamage again since they are inherited. The same goes for the methods. However, the attack method should print something different, so it will be reimplemented.

In the copy constructor, I will also call the ClapTrap copy constructor first.

## ex02
Another inherited class, FragTrap.

## ex03
Now we get to the heart of the matter with the diamond problem.
We create a DiamondTrap which inherits from both the ScavTrap and FragTrap. Of course, they inherit from ClapTrap, so will the constructor for ClapTrap be created twice?  

The Diamond Problem is a common issue that arises in object-oriented programming languages that support multiple inheritance. It's named after the shape of the class diagram that illustrates the problem, which looks like a diamond.
```
  A
 / \
B   C
 \ /
  D
```
In the diagram above, class D inherits from both B and C. If B and C have a member function with the same name, which one does D inherit? C++ allows multiple inheritance, but it has its own way of solving the diamond problem: through the use of virtual inheritance. By declaring the inheritance from A to B and C as virtual, C++ ensures that only one copy of A's members is included in D. This means that there's only one possible implementation of the method in D, which avoids ambiguity.

To avoid this, we use virtual inheritance:
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
https://en.wikipedia.org/wiki/Multiple_inheritance#The_diamond_problem  
