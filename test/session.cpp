// Unit tests for the sources in folder "session-manager"

#include "gtest.h"
#include "session.h"

TEST(Session, CreateDefault) {
    session::Session session(nullptr);
}