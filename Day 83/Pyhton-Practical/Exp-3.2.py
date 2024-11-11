"""
AIM: To demonstrate Object-Oriented Programming (OOP) concepts in Python.

S/W Requirement: Python 3.11 (Install the latest version according to your system).

Inheritance: Mechanism where a new class inherits properties and behavior (methods) from an existing class.

Polymorphism: Ability to present the same interface for different underlying forms (data types).

Encapsulation: Bundling the data and methods that operate on the data within one unit (class), and restricting access to some of the object's components.

Abstraction: Hiding the complex implementation details and showing only the necessary features of the object.

isinstance(): Function to check if an object is an instance of a specific class or a tuple of classes.

issubclass(): Function to check if a class is a subclass of another class.
"""

class Animal:
    def __init__(self, name):
        self.name = name

    def speak(self):
        raise NotImplementedError("Subclass must implement abstract method")

class Dog(Animal):
    def speak(self):
        return f"{self.name} says Woof!"

class Cat(Animal):
    def speak(self):
        return f"{self.name} says Meow!"

class Cow(Animal):
    def speak(self):
        return f"{self.name} says Moo!"

# Function demonstrating polymorphism
def animal_sound(animal):
    return animal.speak()

# Main program
if __name__ == "__main__":
    print("Simple Object-Oriented Programming Demo")
    print("=======================================")

    # Creating instances
    dog = Dog("Buddy")
    cat = Cat("Whiskers")
    cow = Cow("Bessie")

    # List of animals
    animals = [dog, cat, cow]

    # Demonstrating inheritance and polymorphism
    print("\nAnimals speaking:")
    for animal in animals:
        print(animal_sound(animal))

    # Demonstrating isinstance
    print("\nType checking:")
    print(f"Is Buddy a Dog? {isinstance(dog, Dog)}")  # Is Buddy a Dog? True
    print(f"Is Whiskers an Animal? {isinstance(cat, Animal)}")  # Is Whiskers an Animal? True

    # Demonstrating issubclass
    print("\nClass relationship:")
    print(f"Is Dog a subclass of Animal? {issubclass(Dog, Animal)}")  # Is Dog a subclass of Animal? True