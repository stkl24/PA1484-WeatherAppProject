#ifndef LIST_HPP
#define LIST_HPP

#include <vector>
#include <string>

class List {
private:
    std::vector<std::vector<std::string>> grid;
    
public:
    int size() const {
        return grid.size();
    }

    void addData(const std::string& date, const std::string& time, const std::string& temp) {
        grid.push_back({date, time, temp});
    }

    void cloneData(const List& other) {
        grid = other.grid;
    }
    std::vector<std::string> getData(int index){
        if (grid.size() <= index) {
            throw std::out_of_range("Index out of range");
        } else
        {
            return grid[index];
        }
        
       
    }
   
};

#endif // LIST_HPP