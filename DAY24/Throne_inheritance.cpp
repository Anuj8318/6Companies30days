// 1600. Throne Inheritance
// https://leetcode.com/problems/throne-inheritance/

class ThroneInheritance {
private:
   string king ;
   unordered_map<string, vector<string>> familyTree;
   unordered_set<string>dead;

   void dfs(const string& name, vector<string>& order)
   {
      if(dead.find(name)==dead.end())
      {
        order.push_back(name);
      }
      for(const string &child:familyTree[name])
      {
       dfs(child,order);
      }
   } 
public:
    ThroneInheritance(string kingName) {
       king = kingName;  
        familyTree[king] = {};  
    }
    
    void birth(string parentName, string childName) {
        familyTree[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string>order;
        dfs(king,order);
        return order;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */