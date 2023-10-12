package main

import (
	"github.com/gofiber/fiber/v2"
	"github.com/gofiber/template/html/v2"
)

func main() {

	engine := html.New("./views", ".html")

	app := fiber.New(fiber.Config{
		Views: engine,
	})

	app.Static("/", "./views")
	// app.Static("/", "./views/js")

	app.Get("/", func(c *fiber.Ctx) error {
		return c.Render("contents/CheckSNT/content", fiber.Map{
			"title": "Số nguyên tố",
		}, "layouts/main")
	})

	app.Get("/UCLN_BCNN", func(c *fiber.Ctx) error {
		return c.Render("contents/UCLN_BCNN/content", fiber.Map{
			"title": "UCLN và BCNN",
		}, "layouts/main")
	})

	app.Get("/karaoke", func(c *fiber.Ctx) error {
		return c.Render("contents/karaoke/content", fiber.Map{
			"title": "Tính tiền karaoke",
		}, "layouts/main")
	})

	app.Get("/tinhtiendien", func(c *fiber.Ctx) error {
		return c.Render("contents/tinhtiendien/content", fiber.Map{
			"title": "Tính tiền điện",
		}, "layouts/main")
	})

	app.Get("/doitien", func(c *fiber.Ctx) error {
		return c.Render("contents/doitien/content", fiber.Map{
			"title": "Đổi tiền",
		}, "layouts/main")
	})

	app.Get("/tinhlainganhang", func(c *fiber.Ctx) error {
		return c.Render("contents/tinhlainganhang/content", fiber.Map{
			"title": "Tính lãi ngân hàng",
		}, "layouts/main")
	})

	app.Get("/vaytienmuaxe", func(c *fiber.Ctx) error {
		return c.Render("contents/vaytienmuaxe/content", fiber.Map{
			"title": "Vay tiền mua xe",
		}, "layouts/main")
	})

	app.Get("/sapxepthongtinsv", func(c *fiber.Ctx) error {
		return c.Render("contents/sapxepthongtinsv/content", fiber.Map{
			"title": "Sắp xếp sinh viên",
		}, "layouts/main")
	})

	app.Get("/fpoly_lott", func(c *fiber.Ctx) error {
		return c.Render("contents/fpoly_lott/content", fiber.Map{
			"title": "FPOLY LOTT",
		}, "layouts/main")
	})

	app.Get("/phanso", func(c *fiber.Ctx) error {
		return c.Render("contents/phanso/content", fiber.Map{
			"title": "Tính toán phân số",
		}, "layouts/main")
	})

	app.Listen(":3000")
}
