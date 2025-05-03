#pragma once
/*===
	Includes
===*/
// Native
#include <vector>
#include <unordered_map>
#include <string>
#include <memory>
// Project
/*
	SBEM object set: A set for objects...
*/
template<typename T>
struct SbemObjectTraits {
	static_assert(std::is_class_v<T>, "T must be a class type");

	// Define the necessary properties here
	static std::string GetName(const T& obj) {
		return obj.name; // Assuming 'name' is a member of the type T
	}
};
template<typename T>
class SbemObjectSet {
public:
 /*=== Instance methods ===*/
 template<typename U = T, typename = std::enable_if_t<std::is_same_v<decltype(U::name), std::string>>>
 void push(const std::shared_ptr<T>& objectPtr) {
  objects.push_back(objectPtr);
  dictionary[objectPtr->name] = objectPtr;
 }

 size_t size() const {
  return objects.size();
 }

 void clear() {
  objects.clear();
  dictionary.clear();
 }

 /*=== Instance members ===*/
 std::vector<std::shared_ptr<T>> objects;
 std::unordered_map<std::string, std::shared_ptr<T>> dictionary;
};
