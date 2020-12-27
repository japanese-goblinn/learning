//
//  ContentView.swift
//  SwiftUILayoutExplained
//
//  Created by Kirill on 27.12.20.
//

import SwiftUI

// MARK: - Helpers
import Cocoa

extension CGContext {
    static func pdf(size: CGSize, render: (CGContext) -> ()) -> Data {
        let pdfData = NSMutableData()
        let consumer = CGDataConsumer(data: pdfData)!
        var mediaBox = CGRect(origin: .zero, size: size)
        let pdfContext = CGContext(consumer: consumer, mediaBox: &mediaBox, nil)!
        pdfContext.beginPage(mediaBox: &mediaBox)
        render(pdfContext)
        pdfContext.endPage()
        pdfContext.closePDF()
        return pdfData as Data
    }
}
// MARK: - Implementation

protocol _View {
    associatedtype Body: _View
    
    var body: Body { get }
    func render(context: CGContext, size: CGSize)
}

extension Never: _View {}

extension _View {
    func render(context: CGContext, size: CGSize) {
        body.render(context: context, size: size)
    }
}

extension _View where Body == Never {
    var body: Body {
        fatalError("This should never be called")
    }
}

protocol _Shape {
    func path(in rect: CGRect) -> CGPath
}

struct _ShapeView<S: _Shape>: _View {
    let shape: S
    let color: NSColor
            
    func render(context: CGContext, size: CGSize) {
        context.saveGState()
        context.setFillColor(color.cgColor)
        context.addPath(shape.path(in: CGRect(origin: .zero, size: size)))
        context.fillPath()
        context.restoreGState()
    }
}

struct _Rectangle: _Shape {
    func path(in rect: CGRect) -> CGPath {
        CGPath(rect: rect, transform: nil)
    }
}

struct _Ellipse: _Shape {
    func path(in rect: CGRect) -> CGPath {
        CGPath(ellipseIn: rect, transform: nil)
    }
}

func render<V: _View>(_ view: V, of size: CGSize) -> Data {
    CGContext.pdf(size: size) { context in
        view.render(context: context, size: size)
    }
}

let sample = _ShapeView(shape: _Ellipse(), color: .yellow)

struct ContentView: View {
    var body: some View {
        Image(nsImage: NSImage(data: render(sample, of: CGSize(width: 200, height: 100)))!)
            .frame(maxWidth: .infinity, maxHeight: .infinity)
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
