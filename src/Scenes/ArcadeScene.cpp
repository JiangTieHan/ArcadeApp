#include "ArcadeScene.h"
#include "Screen.h"
#include "Circle.h"
#include "Triangle.h"
#include "AARectangle.h"

ArcadeScene::ArcadeScene()
{
}

void ArcadeScene::Init()
{
}

void ArcadeScene::Update(uint32_t dt)
{
}

void ArcadeScene::Draw(Screen& theScreen)
{
	Circle circle(Vec2D(theScreen.Width() / 2.0f, theScreen.Height() / 2.0f), 50.0f);
	Triangle triangle(Vec2D(50, 50), Vec2D(100, 30), Vec2D(25, 100));
	AARectangle rect(Vec2D(150, 30), Vec2D(200, 200));

	theScreen.Draw(rect, Color::White(), true, Color::Blue());
	theScreen.Draw(circle, Color(0, 255, 0, 150), true, Color(0, 255, 0, 150));
}

const std::string& ArcadeScene::GetSceneName() const
{
	return "Arcade Scene";
}

std::unique_ptr<Scene> ArcadeScene::GetScene(eGame game)
{
	switch (game)
	{
	case TETRIS:
		break;
	case BREAK_OUT:
		break;
	case ASTEROIDS:
		break;
	case PACMAN:
		break;
	case NUM_GAMES:
		break;
	default:
		break;
	}

	return nullptr;
}
