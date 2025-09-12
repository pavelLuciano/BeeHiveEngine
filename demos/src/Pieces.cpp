#include <Pieces.h>

Piece::Piece(Color _color): Prop(PIECE_MODEL)
{
    color= _color;
}
void Piece::update(){}
void Piece::draw(Shader& shader) const
{
    shader.setVec3("color",color);
    Prop::draw(shader);
}


void Abeja::checkAvaliableMoves(){}

void Hormiga::checkAvaliableMoves(){}

void Saltamontes::checkAvaliableMoves(){}

void Arana::checkAvaliableMoves(){}

void Escarabajo::checkAvaliableMoves(){}

void Chinita::checkAvaliableMoves(){}

void Zancudo::checkAvaliableMoves(){}

void Chanchito::checkAvaliableMoves(){}