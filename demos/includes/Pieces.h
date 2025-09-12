#ifndef _PIECES_H_
#define _PIECES_H_
#include <Prop.h>


#define PIECE_MODEL "./assets/Pieza/pieza.obj"
#define PIECE_SHADER "./assets/shaders/piece_fs.glsl"

struct Position
{
    unsigned short int x;
    unsigned short int y;
    unsigned short int z;
};
typedef glm::vec3 Color;
class Piece: public Prop
{
public:
    Position position;
    Color color;
    Piece(Color);
    virtual void checkAvaliableMoves() = 0;
    void canMove();
    void update() override;
    void draw(Shader&) const override;
};

class Abeja : public Piece
{
public:
    using Piece::Piece;
    void checkAvaliableMoves() override;
};
class Hormiga: public Piece
{
public:
    using Piece::Piece;
    void checkAvaliableMoves() override;
};
class Saltamontes: public Piece
{
public:
    using Piece::Piece;
    void checkAvaliableMoves() override;
};
class Arana: public Piece
{
public:
    using Piece::Piece;
    void checkAvaliableMoves() override;
};
class Escarabajo: public Piece
{
public:
    using Piece::Piece;
    void checkAvaliableMoves() override;
};
class Chinita: public Piece
{
public:
    using Piece::Piece;
    void checkAvaliableMoves() override;
};
class Zancudo: public Piece
{
public:
    using Piece::Piece;
    void checkAvaliableMoves() override;
};
class Chanchito: public Piece
{
public:
    using Piece::Piece;
    void checkAvaliableMoves() override;
};
#endif