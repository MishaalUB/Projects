@extends('layouts.master')

@section('title')
    Shopping Cart
@endsection

@section('content')
    @foreach($products->chunk(3) as $productChunk)
        <div class="row">
            @foreach($productChunk as $product)
                <div class="col-sm-6 col-md-4 card">
                    <div class="thumbnail pt-4">
                        <img src="{{ $product->imagePath }}" class="mx-auto d-block" alt="">
                        <div class="caption">
                            <h3 class="pt-3">{{ $product->title }}</h3>
                            <p class="description">{{ $product->description }}</p>

                            <div class="clearfix">
                                <div class="pb-2 price">
                                    ${{ $product->price }}
                                </div>
                                <a href="{{ route('product.addToCart', ['id' => $product->id]) }}" class="btn btn-primary float-right" role="button">Add to Cart</a>
                            </div><br>
                        </div>
                    </div>
                </div>
            @endforeach
        </div>
    @endforeach
@endsection

