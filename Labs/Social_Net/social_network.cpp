///Header include
#include "social_network.hpp"
#include "user.hpp"

///STD include
#include <iostream>

namespace SocialNetworkNS {
size_t SocialNetwork::CUserIndex(const std::string &name,
                                 const std::string &surname) const {
  size_t i;

  User u(name, surname);

  bool found = false;

  for (i = 0; i < users.size() && !found; ++i)
    if (users[i] == u)
      found = true;

  if (found)
    return --i;
  else
    return users.size();
}

void SocialNetwork::AddUser(const std::string &name,
                            const std::string &surname) {

  /* YOUR CODE GOES HERE */
  size_t index = CUserIndex(name,surname);
  std::vector<size_t> init;

  if (index==users.size()){
      users.push_back(User(name,surname));
      friends.push_back(init);
  }

}

const std::vector<User> SocialNetwork::CGetUsers() const {
  return users;
}

const std::vector<User> SocialNetwork::CGetFriends(const User &user) const {

  /* YOUR CODE GOES HERE */
  size_t i= CUserIndex(user.CGetName(),user.CGetSurname());

  std::vector<User> f;

  if (i!=friends.size()) {

      for (size_t j = 0; j < friends[i].size(); ++j) {
          f.push_back(users[friends[i][j]]);
      }
  }
  return f;
}

const std::vector<User> SocialNetwork::CGetFriends(const std::string &name,
                                                   const std::string &surname) const {
  std::vector<User> ret{};

  /* YOUR CODE GOES HERE */
  User u=User(name,surname);

  return CGetFriends(u);

}

void SocialNetwork::AddFriendship(const std::string &first_name,
                                  const std::string &first_surname,
                                  const std::string &second_name,
                                  const std::string &second_surname) {

  /* YOUR CODE GOES HERE */
  size_t i= CUserIndex(first_name,first_surname);
  size_t j = CUserIndex(second_name,second_surname);

  if (i == j)
      return;
  if (i == users.size() || j == users.size())
      return;
  if (User(first_name,first_surname)) //using std::find()


  friends[i].push_back(j);
  friends[j].push_back(i);

}

void SocialNetwork::print() {

    for (int i = 0; i < friends.size(); ++i) {
        for (int j = 0; j < friends[i].size(); ++j) {
            std::cout << friends[i][j] << " ";
        }
        std::cout << "\n";
    }

}
}
