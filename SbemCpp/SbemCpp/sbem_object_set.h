#pragma once
/*===
	Includes
===*/
// Native
#include <vector>
#include <unordered_map>
#include <string>
#include <memory>
#include <functional>
#include <algorithm>
// Project
/*
	SBEM object set: A set for objects...
*/



template<typename T>
class SbemObjectSet {
public:
    // === Instance methods ===

    // Only enabled if T has a `std::string name` member
    template<typename U = T, typename = std::enable_if_t<std::is_same_v<decltype(U::name), std::string>>>
    void push(const std::shared_ptr<T>& objectPtr) {
        objects.push_back(objectPtr);
        dictionary[objectPtr->name] = objectPtr;
    }

    size_t size() {
        return objects.size();
    }

    void clear() {
        objects.clear();
        dictionary.clear();
    }
    
    std::shared_ptr<T> at(size_t index) const {
        if (index >= objects.size()) return nullptr;
        return objects[index];
    }

    std::shared_ptr<T> findByName(const std::string& name) const {
        auto it = dictionary.find(name);
        return (it != dictionary.end()) ? it->second : nullptr;
    }

    SbemObjectSet<T> filter(const std::function<bool(const T&)>& predicate) const {
        SbemObjectSet<T> result;
        for (const auto& obj : objects) {
            if (predicate(*obj)) {
                result.push(obj);
            }
        }
        return result;
    }
    float sum(const std::function<bool(const T&)>& func) const {
        float result;
        for (const auto& obj : objects) {
            result  += func(obj);
        }
        return result;
    }

    void each(const std::function<void(const T&)>& fn) const {
        for (const auto& obj : objects) {
            fn(*obj);
        }
    }

    // STL-style iteration
    auto begin() { return objects.begin(); }
    auto end() { return objects.end(); }
    auto begin() const { return objects.begin(); }
    auto end() const { return objects.end(); }

    // === Instance members ===
    std::vector<std::shared_ptr<T>> objects;
    std::unordered_map<std::string, std::shared_ptr<T>> dictionary;
};
