class Bank {
public:
    bool validAccount(int ac) {
        return ac >= 0 && ac < n;
    }
    Bank(vector<long long>& balances) {
        n = balances.size();
        for (auto b : balances) {
            balance.push_back(b);
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        account1--;
        account2--;
        if (validAccount(account1) && validAccount(account2) && balance[account1] >= money) {
            balance[account2] += money;
            balance[account1] -= money;
            return true;
        } else {
            return false;
        }
    }
    
    bool deposit(int account, long long money) {
        account--;
        if (validAccount(account)) {
            balance[account] += money;
            return true;
        } else {
            return false;
        }
    }
    
    bool withdraw(int account, long long money) {
        account--;
        if (validAccount(account) && balance[account] >= money) {
            balance[account] -= money;
            return true;
        }
        return false;
    }
private:
    vector<long long> balance;
    int n;
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */