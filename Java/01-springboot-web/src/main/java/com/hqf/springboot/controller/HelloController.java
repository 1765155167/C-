package com.hqf.springboot.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class HelloController {
    @RequestMapping("/boot/hello")
    @ResponseBody
    String hello() {
        return "Hello Spring Book.";
    }
}
