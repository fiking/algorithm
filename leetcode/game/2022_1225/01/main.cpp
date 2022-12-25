#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int right= -1;
        vector<string> newws;
        newws.reserve(words.size() * 3);
        for (auto &w : words) {
            newws.push_back(w);
        }
        for (auto &w : words) {
            newws.push_back(w);
        }
        for (auto &w : words) {
            newws.push_back(w);
        }
        startIndex = startIndex + words.size();

        for (int i = startIndex; i < words.size() * 3; ++i) {
            if (newws[i] == target) {
                right = i;
                break;
            }
        }

        int left = -1;
        for (int i = startIndex; i >= 0; --i) {
            if (newws[i] == target) {
                left = i;
                break;
            }
        }

        if (left == -1 && right == -1) {
            return -1;
        }
            right = right - startIndex;
            left = startIndex - left;
        return right < left ? right : left;
    }
};

void test(vector<string>& words, string target, int startIndex) {
    Solution solu;
    int ans = solu.closetTarget(words, target, startIndex);
    std::cout << ans << std::endl;
}

void test1() {
    vector<string> words = {
            "odjrjznxpn","cyulttuabe","zqxkdoeszk","yeewpgriok","odjrjznxpn","btqpvxpjzv","ukyudladhk","ukyudladhk","odjrjznxpn","yeewpgriok"
    };
    string target = "odjrjznxpn";
    int startIndex = 5;
    test(words, target, startIndex);
}

void test2() {
    vector<string> words = {
            "hsdqinnoha","mqhskgeqzr","zemkwvqrww","zemkwvqrww","daljcrktje","fghofclnwp","djwdworyka","cxfpybanhd","fghofclnwp","fghofclnwp"
    };
    string target = "zemkwvqrww";
    int startIndex = 8;
    test(words, target, startIndex);
}

void test3() {
    vector<string> words = {
            "aawyoesnjcwqruglyfcnpegnuldlwptcumkiphobxwuxyiwjlf","eaqdovsrujhtcicbfatmipvbwpbmlxanetmalajsfvdwovchtt","quwmjnluvdieyslkkzfvcezbapnpgpdpzeicxnsbxbdjyigogu",
            "xwniqsgthhyrnaljcsbuljblwhyvinlrhcflqdonygyihcezoy","ozxpozhjxckidlryiuwpozxxzazegqwdpsghqpqsoxurwexgnx","quwmjnluvdieyslkkzfvcezbapnpgpdpzeicxnsbxbdjyigogu",
            "chzkqmmgqwtqhdobgiupjqdaxjexhpjssucwtvkajrpazgbbst","chzkqmmgqwtqhdobgiupjqdaxjexhpjssucwtvkajrpazgbbst","beizsenkmlrqhbthcnglbkkysynbwljyxourgqxhhdbrqjwjbe",
            "oooxxzyydbdjvhyhzvlwwlxbefmwbieadomipfvdmoujusdqnr","kgctiokinrfnnnxnbeetjcaswztgtljyisrbjojachfgbujxmn","aawyoesnjcwqruglyfcnpegnuldlwptcumkiphobxwuxyiwjlf",
            "chmffhayhvjezcmcrrdzmtwfatovtesmeaysnaajwzpzktvkhy","xwniqsgthhyrnaljcsbuljblwhyvinlrhcflqdonygyihcezoy","hddpcgzsiixrorozrifikpweqvdfjlankmcunqajyawnpweqep",
            "beizsenkmlrqhbthcnglbkkysynbwljyxourgqxhhdbrqjwjbe","jzoeisnzvqaucssvezmedymvlvlivkuymirmjkaidwrfszmwey","quvrpqrtieoxatfruuininiunzyksoiirytfajdvskovglfyst",
            "fquwwwuqddzzmghlsjkgntrdxcjjdhaturygnwpkqzurwhsnbs","ldimkhaogodsnggnncrlgqjhhrziqlipnpdnalobqtqomhivzb","gedkpyeefquljywyynyyloueewjukvvrflvzbqkslygbjxevln",
            "hddpcgzsiixrorozrifikpweqvdfjlankmcunqajyawnpweqep","chzkqmmgqwtqhdobgiupjqdaxjexhpjssucwtvkajrpazgbbst","quwmjnluvdieyslkkzfvcezbapnpgpdpzeicxnsbxbdjyigogu",
            "xosljdqelacotjmjykzqwfezqyqrzclwaxwnsshxqmfkkbxbsv","holorligkqqbwmuhtdxknbauoaapztgnvzspahmawfnguuxeet","kgctiokinrfnnnxnbeetjcaswztgtljyisrbjojachfgbujxmn",
            "lnsxyyvxwktfrfcnaksfmjcylnuspghtibgobyzbcfndncfqkr","xmmwhwqosxlboizfpjtqtjumqzkfbsqnalpgkhpqlpjyzqbhyn","jurfxnusubbwddfhkixdrtiktmkmdwteemopttiejxvvtdxody",
            "beizsenkmlrqhbthcnglbkkysynbwljyxourgqxhhdbrqjwjbe","uvexttjbcqitczkkfdufmzltnzgrcjkiezbcdgrriehpdbsdno","beizsenkmlrqhbthcnglbkkysynbwljyxourgqxhhdbrqjwjbe",
            "jzoeisnzvqaucssvezmedymvlvlivkuymirmjkaidwrfszmwey","ldnzxsgcpqgiozbbxdjxpgxnlighxtdljbpfjwbbimduusgeam","kgctiokinrfnnnxnbeetjcaswztgtljyisrbjojachfgbujxmn",
            "qciwepmpfsthcshewvuavzditrhuyenwsmaobkvjlzzsunpbok","ozxpozhjxckidlryiuwpozxxzazegqwdpsghqpqsoxurwexgnx","qciwepmpfsthcshewvuavzditrhuyenwsmaobkvjlzzsunpbok",
            "aawyoesnjcwqruglyfcnpegnuldlwptcumkiphobxwuxyiwjlf","kyizgfbeppozaehswgeclpwgomayeujewtkgztdbdzalwfqclm","xmbxnviporjutaxljbfssthsxcagltaltpbvkjaairgauihead",
            "ozxpozhjxckidlryiuwpozxxzazegqwdpsghqpqsoxurwexgnx","uvexttjbcqitczkkfdufmzltnzgrcjkiezbcdgrriehpdbsdno","ptbaikdzpyvjgqttnysohdujpjrkhmvpntmemjrpyewbqanmye",
            "xosljdqelacotjmjykzqwfezqyqrzclwaxwnsshxqmfkkbxbsv","acfztjxiwvceveumejuvzkcpjkrdalaaobwzoystqbreeohirt","eaofhcezozzbrpaecxdccpbvdwvobcrfoizbuqzydburmybxli",
            "wwbonwqbrtuhioyhtzkmqeprjkqzqcfmjxbkigbcsjxtuwfgmv","uwstockselmfmmxukqxjlfzjkkofkglcftenehhahqhjpeyoow"
    };
    string target = "qciwepmpfsthcshewvuavzditrhuyenwsmaobkvjlzzsunpbok";
    int startIndex = 5;
    test(words, target, startIndex);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test2();
    test3();
    return 0;
}