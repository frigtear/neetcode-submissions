class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        std::set<std::string> validEmails;

        for ( const auto& email : emails ) {
            std::string final_email = "";
            bool plus_encountered = false;
            bool at_encountered = false;
            for ( size_t i = 0; i < email.size(); ++i ){
                char character = email[i];

                if ( !at_encountered ){

                    if (character == '@'){
                        at_encountered = true;
                    }
                    else if (character == '.'){
                        continue;
                    }
                    else if (character == '+'){
                        plus_encountered = true;
                        continue;
                    }
                    else if ( plus_encountered ) {
                        continue;
                    }
                }

                final_email += character;
            }  
            validEmails.insert(final_email);
        }

        return validEmails.size();

                

    }
};


    
