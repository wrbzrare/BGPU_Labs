#include <iostream>
#include <vector>

template<typename T>
class Set {
private:
    std::vector<T> items;

    bool containsInternal(const T& item) const {
        for (const T& it : items) {
            if (it == item) return true;
        }
        return false;
    }

public:
    Set() {}

    Set(const std::vector<T>& initialItems) {
        AddRange(initialItems);
    }

    void Add(const T& item) {
        if (Contains(item)) {
            std::cout << "Error: Item already exists in Set\n";
            return;
        }
        items.push_back(item);
    }

    void AddRange(const std::vector<T>& newItems) {
        for (const T& item : newItems) {
            if (Contains(item)) {
                std::cout << "Error: Duplicate item in AddRange\n";
                return;
            }
        }
        for (const T& item : newItems) {
            items.push_back(item);
        }
    }

    bool Remove(const T& item) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (*it == item) {
                items.erase(it);
                return true;
            }
        }
        return false;
    }

    bool Contains(const T& item) const {
        return containsInternal(item);
    }

    int Count() const {
        return static_cast<int>(items.size());
    }

    Set<T> Union(const Set<T>& other) const {
        Set<T> result = *this;
        for (const T& item : other.items) {
            if (!result.Contains(item)) {
                result.Add(item);
            }
        }
        return result;
    }

    Set<T> Intersection(const Set<T>& other) const {
        Set<T> result;
        for (const T& item : items) {
            if (other.Contains(item)) {
                result.Add(item);
            }
        }
        return result;
    }

    Set<T> Difference(const Set<T>& other) const {
        Set<T> result;
        for (const T& item : items) {
            if (!other.Contains(item)) {
                result.Add(item);
            }
        }
        return result;
    }

    Set<T> SymmetricDifference(const Set<T>& other) const {
        Set<T> unionSet = this->Union(other);
        Set<T> intersectionSet = this->Intersection(other);
        return unionSet.Difference(intersectionSet);
    }

    typename std::vector<T>::iterator begin() {
        return items.begin();
    }

    typename std::vector<T>::iterator end() {
        return items.end();
    }

    typename std::vector<T>::const_iterator begin() const {
        return items.begin();
    }

    typename std::vector<T>::const_iterator end() const {
        return items.end();
    }

    void Print() const {
        std::cout << "{ ";
        for (const T& item : items) {
            std::cout << item << " ";
        }
        std::cout << "}\n";
    }
};

