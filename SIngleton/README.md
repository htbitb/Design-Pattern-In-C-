### Singleton instance
Ensure a class only has one instance, and provide a global point of access to it.

### Implementation
* The class is made responsible for its own instance
* It intercepts the call for construction and returns a single instance
* Same instance is returned every time
* Therefore, direct construction of object is disabled
* The class creates its own instance which is provided to the clients

|**Singleton**|
--
|Static Instance() <br> SingletonOperation() <br> GetSingletonData()|
|Static uniqueInstance <br> singletonData|