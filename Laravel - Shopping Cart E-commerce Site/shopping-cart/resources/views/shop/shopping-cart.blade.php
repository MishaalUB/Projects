@extends('layouts.master')

@section('title')
    Shopping Cart
@endsection

@section('content')
    @if(\Illuminate\Support\Facades\Session::has('cart'))
        <div class="row">
            <div class="col-sm-6 col-md-6 col-md-offset-3 col-sm-offset-3">
                <ul class="list-group pt-5">
                    @foreach($products as $product)
                        <li class="list-group-item">
                            <span class="badge border" style="color: #2d3748">{{ $product['qty'] }}</span>
                            <strong>{{ $product['item']['title'] }}</strong>
                            <span class="label label-success">${{ $product['price'] }}</span>
                            <div class="btn-group pl-5">
                                <a href="{{ route('product.reduceByOne', ['id' => $product['item']['id']]) }}" class="btn btn-primary">Reduce by 1</a>
                                <a href="{{ route('product.remove', ['id' => $product['item']['id']]) }}" class="btn btn-primary">Reduce All</a>
                            </div>
                        </li>
                    @endforeach
                </ul>
            </div>
        </div>
        <div class="row">
            <div class="col-sm-6 col-md-6 col-md-offset-3 col-sm-offset-3 pt-3">
                <strong>Total: ${{ $totalPrice }}</strong>
            </div>
        </div>
        <hr>
        <div class="row">
            <div class="col-sm-6 col-md-6 col-md-offset-3 col-sm-offset-3">
                <button type="button" class="btn btn-success">Checkout</button>
            </div>
        </div>
    @else
        <div class="row">
            <div class="col-sm-6 col-md-6 col-md-offset-3 col-sm-offset-3 pt-4">
                <h2>No Items in Cart!</h2>
            </div>
        </div>
    @endif
@endsection
