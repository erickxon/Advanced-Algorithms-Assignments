#include <iostream>
#include <string>

#define max(a,b) ((a) > (b) ? (a) : (b))

//O(n^2) source: https://leetcode.com/problems/multiply-strings/discuss/425870/C%2B%2B-100-time-80%2B-space-solution
//karatsuba algorithm source: https://drawar.github.io/karatsuba-cpp/


using namespace std;

string add(string lhs, string rhs) {
    int length = max(lhs.size(), rhs.size());
    int carry = 0;
    int sum_col;  // sum of two digits in the same column
    string result;

    // pad the shorter string with zeros
    while (lhs.size() < length) 
      lhs.insert(0,"0");
            
    while (rhs.size() < length) 
      rhs.insert(0,"0");

    // build result string from right to left
    for (int i = length-1; i >= 0; i--) {
      sum_col = (lhs[i]-'0') + (rhs[i]-'0') + carry;
      carry = sum_col/10;
      result.insert(0,to_string(sum_col % 10));
    }
    
    if (carry)
      result.insert(0,to_string(carry));
    
    // remove leading zeros
    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

string subtract(string lhs, string rhs) {
    int length = max(lhs.size(), rhs.size());
    int diff;
    string result;

    while (lhs.size() < length) 
      lhs.insert(0,"0");
            
    while (rhs.size() < length) 
      rhs.insert(0,"0");

    for (int i = length-1; i >= 0; i--) {
        diff = (lhs[i]-'0') - (rhs[i]-'0');
        if (diff >= 0)
            result.insert(0, to_string(diff));
        else {

            // borrow from the previous column
            int j = i - 1;
            while (j >= 0) {
                lhs[j] = ((lhs[j]-'0') - 1) % 10 + '0';
                if (lhs[j] != '9') 
                    break;
                else 
                    j--;
            }
            result.insert(0, to_string(diff+10));
        }
      
    }

    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

string multiply5(string lhs, string rhs) {
    int length = max(lhs.size(), rhs.size());
    
    while (lhs.size() < length) 
      lhs.insert(0,"0");

    while (rhs.size() < length) 
      rhs.insert(0,"0");

    if (length == 1)
        return to_string((lhs[0]-'0')*(rhs[0]-'0'));

    string lhs0 = lhs.substr(0,length/2);
    string lhs1 = lhs.substr(length/2,length-length/2);
    string rhs0 = rhs.substr(0,length/2);
    string rhs1 = rhs.substr(length/2,length-length/2);
    
    string p0 = multiply5(lhs0,rhs0);
    string p1 = multiply5(lhs1,rhs1);
    string p2 = multiply5(add(lhs0,lhs1),add(rhs0,rhs1));
    string p3 = subtract(p2,add(p0,p1));

    for (int i = 0; i < 2*(length-length/2); i++)
        p0.append("0");
    for (int i = 0; i < length-length/2; i++)
        p3.append("0");
        
    string result = add(add(p0,p1),p3);

    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

long multiply4(string a,string b){

    long i = std::stol(multiply5(a,b));
    return i;
}



   string multiply2(string n1, string n2) {
        int i = 0, maxSize = n1.size() + n2.size(), prod = 0, j;
        string res(maxSize, '0');
        while (i++ < n1.size() || prod) {
            j = 0;
            while (j++ < n2.size() || prod) {               prod = (i <= n1.size() ? (n1[n1.size() - i] - 48) : 0) * (j <= n2.size() ? (n2[n2.size() - j] - 48) : 0) + prod + res[maxSize - j - i + 1] - 48;
                res[maxSize - j + 1 - i] = (prod % 10) + 48;
                prod /= 10;
            }
        }
        i = -1;
        while (++i < maxSize - 1 && res[i] == '0') {}
        return res.substr(i);
    }

long multiply3(string a,string b){

    long i = std::stol(multiply2(a,b));
    return i;
}

    


int main()
{

    std::clock_t start;
    double duration;
    start = std::clock();
    printf("%ld\n",multiply4("1234","4321"));
    std::cout<<"multipl4-1 time: "<< duration <<'\n';
std::clock_t start1;
double duration1;
start1 = std::clock();
duration1 = ( std::clock() - start1 ) / (double) CLOCKS_PER_SEC;
    printf("%ld\n",multiply3("1234","4321"));
    std::cout<<"multipl3-1 time: "<< duration1 <<'\n';
std::clock_t start2;
double duration2;
start2 = std::clock();
duration2 = ( std::clock() - start2 ) / (double) CLOCKS_PER_SEC;
    printf("%ld\n",multiply4("110","220"));
    std::cout<<"multipl4-2 time: "<< duration2 <<'\n';
std::clock_t start3;
double duration3;
start3 = std::clock();
duration3 = ( std::clock() - start3 ) / (double) CLOCKS_PER_SEC;
    printf("%ld\n",multiply3("110","220"));
    std::cout<<"multipl3-2 time: "<< duration3 <<'\n';
std::clock_t start4;
double duration4;
start4 = std::clock();
duration4 = ( std::clock() - start4 ) / (double) CLOCKS_PER_SEC;
    printf("%ld\n",multiply4("14589","912"));
    std::cout<<"multipl4-3 time: "<< duration4 <<'\n';
std::clock_t start5;
double duration5;
start5 = std::clock();
duration5 = ( std::clock() - start5 ) / (double) CLOCKS_PER_SEC;
    printf("%ld\n",multiply3("14589","912"));
    std::cout<<"multipl3-2 time: "<< duration5 <<'\n';
std::clock_t start6;
double duration6;
start6 = std::clock();
duration6 = ( std::clock() - start6 ) / (double) CLOCKS_PER_SEC;
    printf("%ld\n",multiply4("7777777","88888888"));
    std::cout<<"multipl4-4 time: "<< duration6 <<'\n';
std::clock_t start7;
double duration7;
start7 = std::clock();
duration7 = ( std::clock() - start7 ) / (double) CLOCKS_PER_SEC;
    printf("%ld\n",multiply3("7777777","88888888"));
    std::cout<<"multipl3-4 time: "<< duration7 <<'\n'; 
}