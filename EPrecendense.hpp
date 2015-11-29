#pragma once

enum class EPrecendence
{
    LogicalOr = 5,
    LogicalAnd = 6,
    Comparison = 10,
    Value = 100,
    NodeToRemove = 1000,
    Dummy = -2000
};

