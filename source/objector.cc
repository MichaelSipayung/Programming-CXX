#include "objector.h"
Bulk_quote::Bulk_quote(const std::string& s, double p, std::size_t total,double disc)
    :Quote{s,p},min_qty{total},discount{disc}{}
