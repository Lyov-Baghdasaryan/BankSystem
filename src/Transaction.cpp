#include "../header/Transaction.h"

Transaction::Transaction(Account* fromAccount, Account* toAccount, double amount, const std::string& transactionType)
  : m_fromAccount(fromAccount), m_toAccount(toAccount), m_amount(amount), m_transactionType(transactionType) {}

std::string Transaction::getType(){
  return m_transactionType;
}

double Transaction::getAmount(){
  return m_amount;
}

void Transaction::log(){
  std::cout << "From -> " << m_fromAccount->getAccountType() << std::endl;
  std::cout << "To -> " << m_toAccount->getAccountType() << std::endl;
  std::cout << "Amount -> " << m_amount << std::endl;
  std::cout << "Transaction type -> " << m_transactionType << std::endl;
}