/**
 * @file doxygen_template.h
 * @brief Template file showing Doxygen documentation examples
 * @author Your Name
 * @date 2023
 */

/**
 * @mainpage Qt Client Server Documentation
 *
 * @section intro_sec Introduction
 * This is the documentation for the Qt Client Server project.
 * The project consists of a client application and a server application
 * that communicate using a custom protocol.
 *
 * @section architecture Architecture
 * The project uses the Singleton pattern for client and database connections.
 * Communication between components is described in the UseCase diagram.
 *
 * @section modules Modules
 * - Client - GUI application for end users
 * - Server - Backend server handling requests
 * - Common - Shared code used by both client and server
 *   - Crypto - Cryptographic functions
 *   - Math - Mathematical algorithms
 *   - Network - Network protocol and user management
 *   - Steganography - Steganography algorithms
 */

/**
 * @brief Example class with Doxygen documentation
 *
 * Detailed description of the class. This can span multiple lines
 * and provide more information about the class's purpose and usage.
 */
class ExampleClass
{
public:
    /**
     * @brief Constructor for ExampleClass
     * @param param1 Description of first parameter
     * @param param2 Description of second parameter
     */
    ExampleClass(int param1, const std::string& param2);
    
    /**
     * @brief Destructor for ExampleClass
     */
    ~ExampleClass();
    
    /**
     * @brief Example method that does something
     * @param input The input value
     * @return The result of the operation
     * @throws std::runtime_error If something goes wrong
     *
     * This method performs a specific operation and returns the result.
     * It may throw an exception if the operation fails.
     */
    int doSomething(double input);
    
    /**
     * @brief Gets the current status
     * @return The current status as a string
     */
    std::string getStatus() const;
    
    /**
     * @brief Sets a new value
     * @param newValue The new value to set
     * @pre newValue must be positive
     * @post The internal value will be updated
     */
    void setValue(int newValue);
    
private:
    /**
     * @brief Helper method used internally
     * @param data The data to process
     * @return The processed data
     */
    double processData(double data);
    
    int m_value;       ///< The current value
    std::string m_name; ///< The name of this instance
};

/**
 * @brief Example function outside of a class
 * @param a First parameter
 * @param b Second parameter
 * @return The result of the operation
 */
int exampleFunction(int a, int b);

/**
 * @enum ExampleEnum
 * @brief Example enumeration
 */
enum ExampleEnum
{
    VALUE_ONE,   ///< First value
    VALUE_TWO,   ///< Second value
    VALUE_THREE  ///< Third value
};

/**
 * @struct ExampleStruct
 * @brief Example structure
 */
struct ExampleStruct
{
    int x;       ///< X coordinate
    int y;       ///< Y coordinate
    double value; ///< Some value
};

/**
 * @def MAX_SIZE
 * @brief Maximum size constant
 */
#define MAX_SIZE 100

/**
 * @namespace ExampleNamespace
 * @brief Example namespace
 */
namespace ExampleNamespace
{
    /**
     * @brief Function in the namespace
     */
    void namespaceFunction();
}

/**
 * @page example_page Example Page
 *
 * This is an example of a separate documentation page.
 *
 * @section example_section Example Section
 *
 * This is a section within the page.
 *
 * @subsection example_subsection Example Subsection
 *
 * This is a subsection within the section.
 */

/**
 * @example example_code.cpp
 * This is an example of how to use the library.
 */ 