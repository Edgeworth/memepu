#include "memelang/types.h"

namespace memelang {

Node::Node(const Token& tok) : loc(tok.loc), size(tok.size) {}

Typename::Typename(const Token& tok) : Node(tok) {}

std::string Typename::toString() const { return ""; }

void Typename::generateIr() const {}

Qualifier::Qualifier(const Token& tok) : Node(tok) {}

std::string Qualifier::toString() const { return ""; }

void Qualifier::generateIr() const {}

Type::Type(const Token& tok) : Node(tok) {}

std::string Type::toString() const { return ""; }

void Type::generateIr() const {}

FnVarDecl::FnVarDecl(const Token& tok) : Node(tok) {}

std::string FnVarDecl::toString() const { return ""; }

void FnVarDecl::generateIr() const {}

FnSig::FnSig(const Token& tok) : Node(tok) {}

std::string FnSig::toString() const { return ""; }

void FnSig::generateIr() const {}

IntfDefn::IntfDefn(const Token& tok) : Node(tok) {}

std::string IntfDefn::toString() const { return ""; }

void IntfDefn::generateIr() const {}

File::File(const Token& tok) : Node(tok) {}

std::string File::toString() const { return ""; }

void File::generateIr() const {}

}  // memelang
