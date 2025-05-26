#pragma once

class Location {
protected:
    int X, Y;
public:
    Location(int InitX = 0, int InitY = 0);
    virtual ~Location();
    int GetX() const;
    int GetY() const;
    void SetX(int NewX);
    void SetY(int NewY);
    void SetPosition(int NewX, int NewY);
};

class Point : public Location {
protected:
    bool Visible;
public:
    Point(int InitX = 0, int InitY = 0);
    virtual ~Point();
    bool IsVisible() const;
    virtual void Show();
    virtual void Hide();
    virtual void MoveTo(int NewX, int NewY);
    virtual void Drag(int Step);
};

class Tank : public Point {
protected:
    int bodyWidth, bodyHeight, turretWidth, turretHeight;
    int gunLength, trackHeight;
    int health;
    int speed;
    bool isDestroyed;
public:
    Tank(int InitX, int InitY, int bW, int bH, int tW, int tH, int gL, int trH, int spd = 30);
    virtual ~Tank();
    virtual void Show();
    virtual void Hide();
    virtual void Drag(int step);
    virtual void TakeDamage(int dmg);
    void Heal(int amount);
    void Explode();
    int GetHealth() const;
    int GetSpeed() const;
    int GetBodyWidth() const;
    int GetBodyHeight() const;
    bool IsDestroyed() const;
};

class HeavyTank : public Tank {
private:
    static const int HEAVY_BODY_WIDTH = 320;
    static const int HEAVY_BODY_HEIGHT = 140;
    static const int HEAVY_TURRET_WIDTH = 140;
    static const int HEAVY_TURRET_HEIGHT = 90;
    static const int HEAVY_GUN_LENGTH = 200;
    static const int HEAVY_TRACK_HEIGHT = 50;
    static const int HEAVY_SPEED = 20;
    int targetX, targetY;
public:
    HeavyTank(int InitX, int InitY);
    ~HeavyTank();
    void Show() override;
    void TakeDamage(int dmg) override;
    void SetTarget(int x, int y);
    void ShowTargetingSystem();
};

class LightTank : public Tank {
private:
    static const int LIGHT_BODY_WIDTH = 160;
    static const int LIGHT_BODY_HEIGHT = 70;
    static const int LIGHT_TURRET_WIDTH = 0;
    static const int LIGHT_TURRET_HEIGHT = 0;
    static const int LIGHT_GUN_LENGTH = 0;
    static const int LIGHT_TRACK_HEIGHT = 20;
    static const int LIGHT_SPEED = 50;
public:
    LightTank(int InitX, int InitY);
    ~LightTank();
    void Show() override;
    void TakeDamage(int dmg) override;
};

class DamageTank : public Tank {
private:
    static const int DAMAGE_BODY_WIDTH = 240;
    static const int DAMAGE_BODY_HEIGHT = 100;
    static const int DAMAGE_TURRET_WIDTH = 100;
    static const int DAMAGE_TURRET_HEIGHT = 60;
    static const int DAMAGE_GUN_LENGTH = 120;
    static const int DAMAGE_TRACK_HEIGHT = 35;
    static const int DAMAGE_SPEED = 35;
public:
    DamageTank(int InitX, int InitY);
    ~DamageTank();
    void Show() override;
    void TakeDamage(int dmg) override;
};

class Rocket : public Point {
private:
    int power;
    int directionX, directionY;
    bool isActive;
    static const int ROCKET_WIDTH = 36;
    static const int ROCKET_HEIGHT = 12;
    static const int ROCKET_SPEED = 15;
public:
    Rocket(int InitX, int InitY, int targetX, int targetY, int pwr);
    ~Rocket();
    void Show() override;
    void Hide() override;
    void MoveTo(int NewX, int NewY) override;
    bool CheckCollision(Tank* t);
    void MoveToTarget();
    int GetPower() const;
    bool IsActive() const;
    void Deactivate();
};

class Mina : public Point {
private:
    int damage;
    bool isExploded;
    static const int MINA_WIDTH = 20;
    static const int MINA_HEIGHT = 20;
public:
    Mina(int InitX, int InitY, int dmg = 50);
    ~Mina();
    void Show() override;
    void Hide() override;
    bool CheckCollision(Tank* t);
    void Explode();
    int GetDamage() const;
    bool IsExploded() const;
};

class Remont : public Point {
private:
    int healAmount;
    bool isUsed;
    static const int REMONT_WIDTH = 40;
    static const int REMONT_HEIGHT = 30;
public:
    Remont(int InitX, int InitY, int heal = 30);
    ~Remont();
    void Show() override;
    void Hide() override;
    bool CheckCollision(Tank* t);
    void Use();
    int GetHealAmount() const;
    bool IsUsed() const;
};
